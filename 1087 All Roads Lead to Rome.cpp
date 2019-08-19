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
int n, k, des;
struct edge {
	int index;
	int cost;
};
int dist[205];
int cost[205];
int happy[205];
int ttrds[205];
int path[205];
int v[205];

int hps[205];
vector<vector<edge>> g;
map<string, int> name2id;
map<int, string> id2name;
int getmin() {
	int mini = -1, mincost = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if (!v[i] && cost[i] < mincost) {
			mini = i;
			mincost = cost[i];
		}
	}
	return mini;
}
int main()
{
	string start, c, c2;
	int h;
	cin >> n >> k >> start;
	g.resize(n);
	name2id[start] = 0;
	id2name[0] = start;
	for (int i = 1; i < n; ++i) {
		cin >> c >> h;
		hps[i] = h;
		name2id[c] = i;
		id2name[i] = c;
	}
	for (int i = 0; i < k; ++i) {
		cin >> c >> c2 >> h;
		g[name2id[c]].push_back(edge{ name2id[c2],h });
		g[name2id[c2]].push_back(edge{ name2id[c],h });
	}
	des = name2id["ROM"];
	for (int i = 1; i < n; ++i) {
		cost[i] = INT_MAX;
		path[i] = i;
	}
	ttrds[0] = 1;
	int cur = 0;
	while (cur >= 0) {
		if (cur == des) break;
		v[cur] = 1;
		for (auto &e : g[cur]) {
			if (!v[e.index]) {
				if (cost[e.index] > cost[cur] + e.cost) {
					happy[e.index] = happy[cur] + hps[e.index];
					ttrds[e.index] = ttrds[cur];
					cost[e.index] = cost[cur] + e.cost;
					dist[e.index] = dist[cur] + 1;
					path[e.index] = cur;
				}
				else if (cost[e.index] == cost[cur] + e.cost) {
					ttrds[e.index] += ttrds[cur];
					if (happy[e.index] < happy[cur] + hps[e.index] || 
						(happy[e.index] == happy[cur] + hps[e.index] && dist[e.index] > dist[cur] + 1)) {
						happy[e.index] = happy[cur] + hps[e.index];
						dist[e.index] = dist[cur] + 1;
						path[e.index] = cur;
					}
				}
			}
		}
		cur = getmin();
	}
	cout << ttrds[des] << ' ' << cost[des] << ' ' << happy[des] << ' ' << happy[des] / dist[des] << endl;
	vector<int> ans;
	while (path[des] != des) {
		ans.push_back(des);
		des = path[des];
	}
	ans.push_back(0);
	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << id2name[ans[i]];
		if (i != 0) cout << "->";
	}
	return 0;
}