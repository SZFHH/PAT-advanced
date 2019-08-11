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
vector<vector<edge>> graph;
int v[10005], len[10005];
int n;
int allvisited() {
	for (int i = 1; i <= n; ++i) {
		if (!v[i])
			return i;
	}
	return 0;
}
int FWT(int rt) {
	int depth = 0;
	v[rt] = true;
	queue<int> q;
	int last = rt, tmplast;
	q.push(rt);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto &eg : graph[cur]) {
			if (!v[eg]) {
				v[eg] = true;
				q.push(eg);
				tmplast = eg;
			}
		}
		if (cur == last) {
			last = tmplast;
			depth++;
		}
	}
	return depth;
}
int cnums() {
	int c = 0, v;
	while (v=allvisited()) {
		c++;
		FWT(v);
	}
	return c;
}
int main()
{
	scanf("%d", &n);
	graph.resize(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	int num = cnums();
	if (num > 1) {
		printf("Error: %d components", num);
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		memset(v, 0, sizeof(v));
		len[i] = FWT(i);
	}
	int maxlen = *max_element(len + 1, len + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (len[i] == maxlen) {
			printf("%d\n", i);
		}
	}
	return 0;
}