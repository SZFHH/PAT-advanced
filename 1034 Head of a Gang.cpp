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
int m_stoi(const string &s) {
	int sum = 0;
	for (int i = 0; i < 3; ++i)
		sum = sum * 26 + s[i] - 'A';
	return sum;
}
string m_itos(int n) {
	string rv;
	while (n > 0) {
		rv.push_back(n % 26 + 'A');
		n /= 26;
	}
	while (rv.size() < 3)
		rv.push_back('A');
	reverse(rv.begin(), rv.end());
	return rv;
}
int co[18000];
int m_time[18000];
int findroot(int n) {
	while (co[n] > 0)
		n = co[n];
	return n;
}
inline void merge(int rt1, int rt2) {
	if(rt1!=rt2) co[rt2] = rt1;
}
struct gang {
	int head, headtt, gangtt, ttmem;
	bool operator<(gang g) { return head < g.head; }
	void operator+=(gang g) {
		head = headtt > g.headtt ? head : g.head;
		headtt = max(g.headtt, headtt);
		gangtt += g.gangtt;
		ttmem += g.ttmem;
	}
};
gang allg[1005];
int main()
{
	int n, k, ct = 0, t;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		string p1, p2;
		cin >> p1 >> p2 >> t;
		int i1(m_stoi(p1) + 1), i2(m_stoi(p2) + 1), gno;
		int rt1 = findroot(i1), rt2 = findroot(i2);
		if (!co[rt1] && !co[rt2]) {
			ct++;
			co[rt1] = -ct;
			allg[-co[rt1]].ttmem += 2;
		}
		else if (co[rt1] && !co[rt2]) {
			allg[-co[rt1]].ttmem++;
		}
		else if (!co[rt1] && co[rt2]) {
			swap(rt1, rt2);
			allg[-co[rt1]].ttmem++;
		}
		else if (co[rt1] != co[rt2]) {
			allg[-co[rt1]] += allg[-co[rt2]];
			allg[-co[rt2]].ttmem = 0;
		}
		merge(rt1, rt2);
		gno = -co[rt1];
		m_time[i1] += t, m_time[i2] += t;
		allg[gno].gangtt += t;
		int maxi = m_time[i1] > m_time[i2] ? i1 : i2;
		if (m_time[maxi] > allg[gno].headtt) {
			allg[gno].headtt = m_time[maxi];
			allg[gno].head = maxi;
		}
	}
	int sum = 0;
	for (int i = 1; i <= ct; ++i) {
		if (allg[i].gangtt > k && allg[i].ttmem > 2) sum++;
	}
	sort(allg + 1, allg + ct + 1);
	cout << sum << endl;
	for (int i = 1; i <= ct; ++i) {
		if (allg[i].gangtt > k && allg[i].ttmem > 2)
			cout << m_itos(allg[i].head - 1) << ' ' << allg[i].ttmem << endl;
	}
	return 0;
}