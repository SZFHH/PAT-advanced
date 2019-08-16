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
int n, k, m, tmp;
int fullgd[6];
struct testee {
	int id;
	int gd[6], tt, pct;
	bool hass;
	bool operator<(testee t) {
		if(tt!=t.tt) return tt > t.tt;
		else {
			if (pct != t.pct) return pct > t.pct;
			else return id < t.id;
		}
	}
	testee() {
		for (int i = 0; i < 6; ++i) gd[i] = -2;
		tt = 0;
		pct = 0;
		hass = false;
	}
	void caltt() {
		for (int i = 1; i <= k; ++i) {
			if (gd[i] != -2) tt += gd[i];
			if (gd[i] == fullgd[i]) pct++;
		}
	}
	void show() {
		printf("%05d %d", id, tt);
		for (int i = 1; i <= k; ++i) {
			if (gd[i] == -2) printf(" -");
			else printf(" %d", gd[i]);
		}
		putchar('\n');
	}
};
vector<testee> ans;
int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= k; ++i) cin >> fullgd[i];
	ans.resize(10005);
	for (int i = 0; i < m; ++i) {
		int sid, pid, psc;
		scanf("%d%d%d", &sid, &pid, &psc);
		ans[sid].id = sid;
		if (psc != -1) ans[sid].hass = true;
		if (psc == -1) psc = 0;
		ans[sid].gd[pid] = max(ans[sid].gd[pid], psc);
	}
	for (auto &t : ans) t.caltt();
	sort(ans.begin(), ans.end());
	int last(-1), i(1), rk;
	for (auto &t : ans) {
		if (!t.hass) continue;
		if (t.tt != last) {
			rk = i;
			last = t.tt;
		}
		printf("%d ", rk);
		t.show();
		++i;
	}
	return 0;
}
