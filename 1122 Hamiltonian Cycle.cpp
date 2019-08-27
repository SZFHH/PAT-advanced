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
int v[205];
int n, m;
vector<int> tmp;
bool isok() {
	for (int i = 0; i < tmp.size() - 1; ++i) {
		if (!g[tmp[i]][tmp[i + 1]] || v[tmp[i + 1]]) return false;
		v[tmp[i + 1]] = 1;
	}
	return true;
}
int main()
{
	int c1, c2, num;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &c1, &c2);
		g[c1][c2] = 1;
		g[c2][c1] = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &num);
		for (int i = 0; i < num; ++i) {
			scanf("%d", &c1);
			tmp.push_back(c1);
		}
		if (num != n+1 || tmp[0]!=tmp[num-1]) {
			printf("NO\n");
			tmp.clear();
			continue;
		}
		if (isok()) printf("YES\n");
		else printf("NO\n");
		memset(v, 0, sizeof(v));
		tmp.clear();
	}
	return 0;
}