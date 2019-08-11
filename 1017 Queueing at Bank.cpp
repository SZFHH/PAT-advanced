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
using namespace std;

struct m_time {
	int h, m, s;
	int tt;
	m_time(int hour, int minute, int second) :h(hour), m(minute), s(second) {
		caltt();
	}
	m_time() :m_time(0, 0, 0) {};
	bool operator<(m_time t) {
		return tt < t.tt;
	}
	bool operator>(m_time t) {
		return !(this->operator<(t));
	}
	int operator-(m_time m) {
		return tt - m.tt;
	}
	void caltt() {
		tt = (h - 8) * 3600 + m * 60 + s;
	}
};
struct info {
	m_time arvtime;
	int endu;
	info(m_time tim, int en) :arvtime(tim), endu(60 * en) {};
	bool operator<(info i) {
		return arvtime < i.arvtime;
	}
};
istream & operator >> (istream & in, m_time & t) {
	scanf("%d:%d:%d", &t.h, &t.m, &t.s);
	t.caltt();
	return in;
}

int sum;
int lastfns[105];

int main()
{
	int n, k;
	cin >> n >> k;
	vector<info> users;
	for (int i = 0; i < n; ++i) {
		m_time tmptime;
		int endu;
		cin >> tmptime >> endu;
		if(tmptime<m_time(17,0,1))
			users.push_back(info(tmptime, endu));
	}
	sort(users.begin(), users.end());
	for (auto &us : users) {
		int* minp = min_element(lastfns + 1, lastfns + 1 + k);
		if (us.arvtime.tt < *minp) {
			sum += *minp - us.arvtime.tt;
			*minp += us.endu;
		}
		else
			*minp = us.arvtime.tt + us.endu;
	}
	cout << fixed << setprecision(1);
	cout << sum / 60.0 / users.size() << endl;
	return 0;
}