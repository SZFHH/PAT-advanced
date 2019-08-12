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
int n, m, s, d;
int v[505];
int graph[505][505];
int cost[505][505];
int path[505];
int dist[505];
int ttcost[505];
int getmin() {
	int mini = -1, minlen = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if (dist[i] < minlen && !v[i]) {
			mini = i;
			minlen = dist[i];
		}
	}
	return mini;
}
int main()
{
	cin >> n >> m >> s >> d;
	for (int i = 0; i < m; ++i) {
		int c1, c2, d, c;
		scanf("%d%d%d%d", &c1, &c2, &d, &c);
		graph[c1][c2] = d;
		graph[c2][c1] = d;
		cost[c1][c2] = c;
		cost[c2][c1] = c;
	}
	for (int i = 0; i < n; ++i) {
		dist[i] = INT_MAX;
		path[i] = i;
	}
	dist[s] = 0;
	path[s] = s;
	int cur = s;
	while (cur != -1) {
		v[cur] = true;
		for (int i = 0; i < n; ++i) {
			if (!v[i] && graph[cur][i]) {
				if ((dist[i] > dist[cur] + graph[cur][i]) || (dist[i] == dist[cur] + graph[cur][i] && ttcost[i] > ttcost[cur] + cost[cur][i])) {
					dist[i] = dist[cur] + graph[cur][i];
					path[i] = cur;
					ttcost[i] = ttcost[cur] + cost[cur][i];
				}
			}
		}
		cur = getmin();
	}
	int pt = d;
	vector<int> output;
	while (pt != path[pt]) {
		output.push_back(pt);
		pt = path[pt];
	}
	output.push_back(s);
	for (int i = output.size() - 1; i >= 0; --i)
		cout << output[i] << ' ';
	cout << dist[d] << ' ' << ttcost[d];
	return 0;
}