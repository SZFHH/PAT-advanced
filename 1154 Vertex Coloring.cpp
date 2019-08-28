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
#include<unordered_set>
#include<set>
#include<limits.h>
#include<queue>
#include<stack>
using namespace std;
int n, m;
vector<vector<int>> g;
int c[10005];
unordered_set<int> s;
bool isok() {
	for (int v = 0; v < n; ++v) {
		for (auto &e : g[v]) {
			if (c[v] == c[e]) return false;
		}
	}
	return true;
}
int main()
{
	int c1, c2;
	scanf("%d%d", &n, &m);
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &c1, &c2);
		g[c1].push_back(c2);
		g[c2].push_back(c1);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		s.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &c[i]);
			s.insert(c[i]);
		}
		if (isok()) printf("%d-coloring\n", s.size());
		else printf("No\n");
	}
	return 0;
}