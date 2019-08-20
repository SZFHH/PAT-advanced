# include <iostream>
# include <functional>
# include <vector>
# include <algorithm>
#include<math.h>
#include<string>
#include<cstring>
#include<iterator>
#include<iomanip>
#include<numeric>
#include<map>
#include<unordered_map>
#include<set>
#include<limits.h>
#include<queue>
#include<stack>
using namespace std;

struct m_time {
	int h, m, s;
	int tts;
	void caltt() {
		tts = h * 3600 + m * 60 + s;
	}
	bool operator<(m_time t) {
		return tts < t.tts;
	}
	m_time(int tts_) {
		tts = tts_;
		h = tts / 3600;
		tts %= 3600;
		m = tts / 60;
		tts %= 60;
		s = tts;
	}
	m_time() :h(0), m(0), s(0), tts(0) {}
};
istream & operator >> (istream &in, m_time & t) {
	scanf("%d:%d:%d", &t.h, &t.m, &t.s);
	t.caltt();
	return in;
}
ostream & operator << (ostream &o, m_time t) {
	printf("%02d:%02d:%02d", t.h, t.m, t.s);
	return o;
}
struct rec {
	string plate;
	int state;
	m_time t;
	bool operator<(rec r) {
		return plate == r.plate ? t < r.t : plate < r.plate;
	}
};
vector<rec> recv;
bool cpm(int i, int j) {
	return recv[i].t < recv[j].t;
}
vector<int> ans, cnt;
map<string, int> enduans;
int n, m;
int main()
{
	scanf("%d%d", &n, &m);
	recv.resize(n);
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> recv[i].plate >> recv[i].t >> tmp;
		if (tmp[0] == 'i') 
			recv[i].state = 1;
		else
			recv[i].state = -1;
	}
	sort(recv.begin(), recv.end());
	for (int i = 0; i < recv.size() - 1; ++i) {
		if (recv[i].plate == recv[i + 1].plate && recv[i].state==1 && recv[i + 1].state==-1) {
			ans.push_back(i);
			ans.push_back(i + 1);
			++i;
		}
	}
	int ct(0), last(0), maxt(0), endu;
	for (int i = 0; i < ans.size() - 1; i += 2) {
		endu = recv[ans[i] + 1].t.tts - recv[ans[i]].t.tts;
		enduans[recv[ans[i]].plate] += endu;
	}
	for (auto &c : enduans) maxt = max(maxt, c.second);
	sort(ans.begin(), ans.end(), cpm);
	cnt.resize(ans.size());
	cnt[0] = 1;
	for (int i = 1; i < cnt.size(); ++i) cnt[i] = cnt[i - 1] + recv[ans[i]].state;
	m_time t;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		while (last < ans.size() && recv[ans[last]].t.tts <= t.tts) ++last;
		printf("%d\n", cnt[--last]);
	}
	for (auto &c : enduans) {
		if (c.second==maxt) printf("%s ", c.first.c_str());
	}
	cout << m_time(maxt);
	return 0;
}