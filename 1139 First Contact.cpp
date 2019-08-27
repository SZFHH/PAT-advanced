#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
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
unordered_map<int, vector<int>> b, g;
set<int> hask;
vector<pair<int, int>> ans;
bool z = false;
int main()
{
	int n, m, p1, p2;
	string sp1, sp2;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		cin >> sp1 >> sp2;
		p1 = atoi(sp1.c_str());
		p2 = atoi(sp2.c_str());
		if (!z && ((p1 == 0 && sp1[0] == '-') || (p2 == 0 && sp2[0] == '-'))) z = true;
		if (p1 < 0 || (p1 == 0 && z)) g[abs(p2)].push_back(-p1);
		else b[abs(p2)].push_back(p1);
		if (p2 < 0 || (p2 == 0 && z)) g[abs(p1)].push_back(-p2);
		else b[abs(p1)].push_back(p2);
		hask.insert(abs(p1) * 10000 + abs(p2));
		hask.insert(abs(p2) * 10000 + abs(p1));

	}
	for (auto &e : b) sort(e.second.begin(), e.second.end());
	for (auto &e : g) sort(e.second.begin(), e.second.end());
	int k;
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &p1, &p2);
		ans.clear();
		unordered_map<int, vector<int>> *fir = &b, *sec= &g;
		if (p1 < 0 || (p1 == 0 && z))  fir = &g;
		if (p2 > 0 || (p2 == 0 && !z)) sec = &b;
		p1 = abs(p1);
		p2 = abs(p2);
		if ((*fir).find(p1) != (*fir).end() && (*sec).find(p2) != (*sec).end()) {
			for (auto &f1 : (*fir)[p1]) {
				if (f1 == p2) continue;
				for (auto &f2 : (*sec)[p2]) {
					if (f2 == p1) continue;
					if (hask.find(f1 * 10000 + f2) != hask.end())
						ans.push_back(make_pair(f1, f2));
				}
			}
		}
		printf("%d\n", ans.size());
		for (auto &p : ans) {
			printf("%04d %04d\n", p.first, p.second);
		}
	}
	return 0;
}