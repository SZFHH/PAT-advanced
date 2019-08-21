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

vector<set<int>> hs;
vector<vector<int>> g;
vector<int> ans;
int hasv[1005];
bool hassameh(set<int> &s1, set<int> &s2) {
	for (auto &i : s1) {
		if (s2.find(i) != s2.end()) return true;
	}
	return false;
}
int DFS(int index) {
	int sum = 1;
	hasv[index] = 1;
	for (auto &e : g[index]) {
		if (!hasv[e]) sum += DFS(e);
	}
	return sum;
}
int main()
{	
	int n, num, h, ct(0);
	scanf("%d", &n);
	hs.resize(n + 1);
	g.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &num);
		getchar();
		for (int j = 0; j < num; ++j) {
			scanf("%d", &h);
			hs[i].insert(h);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (hassameh(hs[i], hs[j])) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!hasv[i]) ans.push_back(DFS(i));
	}
	sort(ans.begin(), ans.end(), greater<int>());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}