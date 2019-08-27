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
int anslen, tmplen, ansct;
int v[10005];
vector<int> path, tmppath;
vector<vector<int>> g(10005);
unordered_map<int, int> line;
int n, src, des;
int getct() {
	int now = line[tmppath[0] * 10000 + tmppath[1]], rv = 0;
	for (int j = 1; j<tmppath.size(); j++) {
		if (line[tmppath[j - 1] * 10000 + tmppath[j]] != now) {
			++rv;
			now = line[tmppath[j - 1] * 10000 + tmppath[j]];
		}
	}
	return rv;
}
void dfs(int s) {
	if (s == des) {
		if (anslen > tmplen) {
			anslen = tmplen;
			ansct = getct();
			path = tmppath;
		}
		else if (anslen == tmplen) {
			int tmpct = getct();
			if (tmpct < ansct) {
				ansct = tmpct;
				path = tmppath;
			}
		}
		return;
	}
	if (anslen <= tmplen) return;
	for (auto &e : g[s]) {
		if (!v[e]) {
			v[e] = 1;
			tmplen++;
			tmppath.push_back(e);
			dfs(e);
			tmppath.pop_back();
			tmplen--;
			v[e] = 0;
		}
	}
}
int main()
{
	int num, c1, c2;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &num);
		scanf("%d", &c1);
		for (int j = 1; j < num; ++j) {
			scanf("%d", &c2);
			g[c1].push_back(c2);
			g[c2].push_back(c1);
			line[c1 * 10000 + c2] = line[c2 * 10000 + c1] = i;
			c1 = c2;
		}
	}
	int m;
	scanf("%d", &m);
	for (int s = 0; s < m; ++s) {
		anslen = INT_MAX;
		scanf("%d%d", &src, &des);
		tmppath.push_back(src);
		v[src] = 1;
		dfs(src);
		v[src] = 0;
		tmppath.pop_back();
		printf("%d\n", anslen);
		int now = line[path[0] * 10000 + path[1]];
		int i = 0, j;
		for (j = 1; j<path.size(); j++) {
			if (line[path[j - 1] * 10000 + path[j]] != now) {
				printf("Take Line#%d from %04d to %04d.\n", now, path[i], path[j - 1]);
				i = j - 1;
				now = line[path[j - 1] * 10000 + path[j]];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", now, path[i], path[j - 1]);
	}
	return 0;
}