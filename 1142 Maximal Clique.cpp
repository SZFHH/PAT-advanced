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
int g[205][205];
int n, m;
int v[205];
vector<int> cl;
bool iscl() {
	if (cl.size() == 1) return true;
	for (int i = 0; i < cl.size(); ++i) {
		for (int j = i + 1; j < cl.size(); ++j) {
			if (!g[cl[i]][cl[j]]) return false;
		}
	}
	return true;
}
bool canj(int n) {
	for (auto &c : cl) {
		if (!g[c][n]) return false;
	}
	return true;
}
bool ismaxcl() {
	for (int i = 1; i <= n; ++i) {
		if (canj(i)) return false;
	}
	return true;
}
int main()
{
	int c1, c2;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &c1, &c2);
		g[c1][c2] = 1;
		g[c2][c1] = 1;
	}
	int k, num, c;
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &num);
		while (num--) {
			scanf("%d", &c);
			v[c] = 1;
			cl.push_back(c);
		}
		if (iscl()) {
			if (ismaxcl()) printf("Yes\n");
			else printf("Not Maximal\n");
		}
		else printf("Not a Clique\n");
		cl.clear();
		memset(v, 0, sizeof(0));
	}
	return 0;
}