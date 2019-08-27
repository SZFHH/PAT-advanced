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
int v[505];
int n, m, e, o, ct;
vector<vector<int>> g;
void dfs(int rt) {
	v[rt] = 1;
	ct++;
	for (auto &e : g[rt]) {
		if (!v[e]) dfs(e);
	}
}
int main()
{
	int c1, c2;
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> c1 >> c2;
		g[c1].push_back(c2);
		g[c2].push_back(c1);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		if (g[i].size() % 2 == 0) e++;
		else o++;
	}
	for (int i = 1; i <= n; ++i) {
		if (i != 1) cout << ' ';
		cout << g[i].size();
	}
	cout << endl;
	if (ct == n && e == n) cout << "Eulerian" << endl;
	else if (ct ==n && e == n - 2) cout << "Semi-Eulerian" << endl;
	else cout << "Non-Eulerian" << endl;
	return 0;
}