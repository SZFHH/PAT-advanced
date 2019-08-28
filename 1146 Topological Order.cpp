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
int degree[1005], tmp[1005];
int n, m;
vector<vector<int>> gout, gin;
vector<int> ans;
bool isok() {
	for (int i = 1; i <= n; ++i) {
		if (degree[tmp[i]] != 0) return false;
		for (auto &e : gout[tmp[i]]) --degree[e];
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	gin.resize(n + 1);
	gout.resize(n + 1);
	int c1, c2;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &c1, &c2);
		gout[c1].push_back(c2);
		gin[c2].push_back(c1);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &tmp[j]);
			degree[j] = gin[j].size();
		}
		if (!isok()) ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); ++i) {
		if (i != 0) cout << ' ';
		cout << ans[i];
	}
	return 0;
}