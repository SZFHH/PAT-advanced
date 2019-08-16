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
int n, m, k, d;
struct edge {
	int index, len;
	edge(int index_, int len_) :index(index_), len(len_) {}
};
struct st {
	int id;
	double m, avg;
	st(int id_, double m_, double avg_) :id(id_), m(m_), avg(avg_) {}
	bool operator<(st s) {
		if (abs(m - s.m)>1e-7) return m > s.m;
		else {
			if (abs(avg - s.avg)>1e-7)return avg < s.avg;
			else return id < s.id;
		}
	}
};
vector<vector<edge>> graph;
vector<st> ans;
int dist[1100];
int v[1100];
int toint(char* s) {
	if (s[0] == 'G') return atoi(s + 1) + n;
	else return atoi(s);
}
int findmin() {
	int mini = 0, mind(INT_MAX);
	for (int i = 1; i <= n + m; ++i) {
		if (!v[i] && dist[i] < mind) {
			mini = i;
			mind = dist[i];
		}
	}
	return mini;
}
void reset(int i) {
	memset(v, 0, sizeof(v));
	for (int i = 0; i < 1100; ++i) dist[i] = INT_MAX;
	v[i] = 1;
	dist[i] = 0;
}
bool isok() {
	for (int i = 1; i <= n; ++i) {
		if (dist[i] > d) return false;
	}
	return true;
}
int main()
{
	char v1[10], v2[10];
	int len, int_v1, int_v2;
	scanf("%d%d%d%d", &n, &m, &k, &d);
	graph.resize(n + m +1);
	for (int i = 0; i < k; ++i) {
		scanf("%s%s%d", v1, v2, &len);
		int_v1 = toint(v1), int_v2 = toint(v2);
		graph[int_v1].push_back(edge(int_v2, len));
		graph[int_v2].push_back(edge(int_v1, len));
	}
	for (int s = n + 1; s <= n + m; ++s) {
		reset(s);
		int cur = s;
		while (cur) {
			for (auto &e : graph[cur]) {
				if(!v[e.index]) dist[e.index] = min(dist[e.index], dist[cur] + e.len);
			}
			cur = findmin();
			v[cur] = true;
		}
		if (isok()) {
			double m, a;
			m = *min_element(dist + 1, dist + 1 + n);
			a = accumulate(dist + 1, dist + 1 + n, 0) / double(n);
			ans.push_back(st(s - n, m, a));
		}
	}
	if (ans.size()) {
		sort(ans.begin(), ans.end());
		printf("G%d\n", ans[0].id);
		printf("%.1f %.1f", ans[0].m, ans[0].avg);
	}
	else printf("No Solution");
	return 0;
}