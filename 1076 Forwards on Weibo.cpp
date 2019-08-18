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
typedef int edge;
vector<vector<edge>> g;
int hasv[1005];
int main()
{
	int n, L, num, v;
	scanf("%d%d", &n, &L);
	g.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &v);
			g[v].push_back(i);
		}
	}
	scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		scanf("%d", &v);
		queue<int> q;
		int last = v, tmplast, ct(0), le(0);
		q.push(v);
		hasv[v] = 1;
		while (!q.empty() && le < L) {
			v = q.front();
			q.pop();
			for (auto &e : g[v]) {
				if (!hasv[e]) {
					hasv[e] = 1;
					q.push(e);
					ct++;
					tmplast = e;
				}
			}
			if (last == v) {
				le++;
				last = tmplast;
			}
		}
		printf("%d\n", ct);
		memset(hasv, 0, sizeof(hasv));
	}
	return 0;
}
