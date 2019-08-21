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

struct edge {
	int index;
	int t, d;
};
int dfdist[505], dftime[505], dfpath[505];
int tfendu[505], tftime[505], tfpath[505];
int v[505];
vector<vector<edge>> g;
int n, m, scr, des;
vector<int> dfans, tfans;
int getmin(int cost[]) {
	int mini(-1), mina(INT_MAX);
	for (int i = 0; i < n; ++i) {
		if (!v[i] && cost[i] < mina) {
			mina = cost[i];
			mini = i;
		}
	}
	return mini;
}
int main()
{	
	int v1, v2, p, t, d;
	scanf("%d%d", &n, &m);
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d%d", &v1, &v2, &p, &d, &t);
		if (!p) g[v2].push_back(edge{ v1,t,d });
		g[v1].push_back(edge{ v2,t,d });

	}
	scanf("%d%d", &scr, &des);
	for (int i = 0; i < n; ++i) {
		dfpath[i] = i;
		tfpath[i] = i;
		dfdist[i] = INT_MAX;
		tftime[i] = INT_MAX;
	}
	dfdist[scr] = 0;
	int cur = scr;
	while (cur != -1) {
		if (cur == des) break;
		v[cur] = 1;
		for (auto &e : g[cur]) {
			if (!v[e.index] && (dfdist[e.index] > dfdist[cur] + e.d || 
				(dfdist[e.index] == dfdist[cur] + e.d && dftime[e.index] > dftime[cur] + e.t))) {
				dfdist[e.index] = dfdist[cur] + e.d;
				dftime[e.index] = dftime[cur] + e.t;
				dfpath[e.index] = cur;
			}
		}
		cur = getmin(dfdist);
	}
	memset(v, 0, sizeof(v));
	cur = scr;
	tftime[scr] = 0;
	tfendu[scr] = 1;
	while (cur != -1) {
		if (cur == des) break;
		v[cur] = 1;
		for (auto &e : g[cur]) {
			if (!v[e.index] && (tftime[e.index] > tftime[cur] + e.t ||
				(tftime[e.index] == tftime[cur] + e.t && tfendu[e.index] > tfendu[cur] + 1))) {
				tftime[e.index] = tftime[cur] + e.t;
				tfendu[e.index] = tfendu[cur] + 1;
				tfpath[e.index] = cur;
			}
		}
		cur = getmin(tftime);
	}
	int last = des;
	while (last != dfpath[last]) {
		dfans.push_back(last);
		last = dfpath[last];
	}
	dfans.push_back(scr);
	last = des;
	while (last != tfpath[last]) {
		tfans.push_back(last);
		last = tfpath[last];
	}
	tfans.push_back(scr);
	if (dfans != tfans) {
		printf("Distance = %d: ", dfdist[des]);
		for (int i = dfans.size() - 1; i >= 0; --i) {
			printf("%d", dfans[i]);
			if (i != 0) printf(" -> ");
		}
		cout << endl;
		printf("Time = %d: ", tftime[des]);
		for (int i = tfans.size() - 1; i >= 0; --i) {
			printf("%d", tfans[i]);
			if (i != 0) printf(" -> ");
		}
	}
	else {
		printf("Distance = %d; Time = %d: ", dfdist[des], tftime[des]);
		for (int i = tfans.size() - 1; i >= 0; --i) {
			printf("%d", tfans[i]);
			if (i != 0) printf(" -> ");
		}
	}
	return 0;
}