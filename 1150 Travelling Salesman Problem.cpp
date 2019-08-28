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
int n, m, num;
vector<int> tmp;
int caldis() {
	int rv = 0;
	for (int i = 0; i < num - 1; ++i) {
		if (g[tmp[i]][tmp[i + 1]]) {
			rv += g[tmp[i]][tmp[i + 1]];
			v[tmp[i + 1]] ++;
		}
		else return INT_MAX;
	}
	return rv;
}
int judge() {
	for (int i = 1; i <= n; ++i) {
		if (v[i] == 0) return 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (v[i] > 1) return 2;
	}
	return 3;
}
int main()
{
	int c1, c2, d;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &c1, &c2, &d);
		g[c1][c2] = d;
		g[c2][c1] = d;
	}
	int q, ansq, ansd = INT_MAX;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		memset(v, 0, sizeof(v));
		tmp.clear();
		scanf("%d", &num);
		tmp.resize(num);
		for (int j = 0; j < num; ++j) scanf("%d", &tmp[j]);
		int d = caldis(), r = judge();
		if (r == 1) {
			if(d==INT_MAX) printf("Path %d: NA (Not a TS cycle)\n", i + 1);
			else printf("Path %d: %d (Not a TS cycle)\n", i + 1, d);
		}
		else if(r==2) printf("Path %d: %d (TS cycle)\n", i + 1, d);
		else printf("Path %d: %d (TS simple cycle)\n", i + 1, d);
		if (r!=1 && d < ansd) {
			ansd = d;
			ansq = i + 1;
		}
	}
	printf("Shortest Dist(%d) = %d", ansq, ansd);
	return 0;
}