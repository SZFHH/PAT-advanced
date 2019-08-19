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

vector<vector<int>> tree;
int main()
{
	int n, m, par, num;
	cin >> n >> m;
	tree.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &par, &num);
		tree[par].resize(num);
		for (int i = 0; i < num; ++i) scanf("%d", &tree[par][i]);
	}
	queue<int> q;
	q.push(1);
	int last(1), tmplast, ct(0), maxct(1), le(1), maxl(1);
	while (!q.empty()) {
		par = q.front();
		q.pop();
		for (auto &chd : tree[par]) {
			q.push(chd);
			tmplast = chd;
			ct++;
		}
		if (par == last) {
			le++;
			if (ct > maxct) {
				maxct = ct;
				maxl = le;
			}
			ct = 0;
			last = tmplast;
		}
	}
	cout << maxct << ' ' << maxl;
	return 0;
}