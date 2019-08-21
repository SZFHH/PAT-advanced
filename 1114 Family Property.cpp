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
struct vertex {
	int mes, area;
	vector<int> edges;
};
struct info {
	int minname, ttp;
	double avs, ava;
	bool operator<(info & info2) {
		return abs(ava - info2.ava)<1e-7 ? minname<info2.minname : ava>info2.ava;
	}
};
vertex g[10005];
vector<info> ans;
int n, minname(10000), ttp, tts, tta;
int v[10005], illegal[100005];
void dfs(int rt) {
	v[rt] = 1;
	if (minname > rt) minname = rt;
	++ttp;
	tts += g[rt].mes;
	tta += g[rt].area;
	for (auto &e : g[rt].edges) {
		if (!v[e]) dfs(e);
	}
}
int main()
{	
	scanf("%d", &n);
	int name, dad, mom, mchid, chd;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &name, &dad, &mom, &mchid);
		illegal[name] = 1;
		if (dad != -1) {
			g[name].edges.push_back(dad);
			g[dad].edges.push_back(name);
			illegal[dad] = 1;
		}
		if (mom != -1) {
			g[name].edges.push_back(mom);
			g[mom].edges.push_back(name);
			illegal[mom] = 1;
		}
		for (int j = 0; j < mchid; ++j) {
			scanf("%d", &chd);
			g[name].edges.push_back(chd);
			g[chd].edges.push_back(name);
			illegal[chd] = 1;
		}
		scanf("%d%d", &g[name].mes, &g[name].area);
	}
	
	for (int i = 0; i < 10005; ++i) {
		if (illegal[i] && !v[i]) {
			minname = 10000, ttp = 0, tts = 0, tta = 0;
			dfs(i);
			ans.push_back(info{ minname,ttp,double(tts)/ttp,double(tta)/ttp });
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (auto &info : ans) {
		printf("%04d %d %.3lf %.3lf\n", info.minname, info.ttp, info.avs, info.ava);
	}
	return 0;
}