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
int n, k, p;
int maxfac;
vector<int> ans, tmp, fac;
void init() {
	int tmp = 0, index = 1;
	while (tmp <= n) {
		fac.push_back(tmp);
		tmp = pow(index, p);
		index++;
	}
}
void dfs(int index, int curk, int curn, int curfac) {
	if (curk == k) {
		if (curn == n && curfac > maxfac) {
			maxfac = curfac;
			ans = tmp;
		}
		return;
	}
	if (index < 1) return;
	if (curn + fac[index] <= n) {
		tmp.push_back(index);
		dfs(index, curk + 1, curn + fac[index], curfac + index);
		tmp.pop_back();
	}
	dfs(index - 1, curk, curn, curfac);
}
int main()
{
	cin >> n >> k >> p;
	init();
	dfs(fac.size()-1, 0, 0, 0);
	if (!maxfac) printf("Impossible");
	else {
		printf("%d = ", n);
		for (int i = 0; i < ans.size(); ++i) {
			if (i != 0) printf(" + ");
			printf("%d^%d", ans[i], p);
		}
	}
	return 0;
}