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
map<int, set<int>> mp;
int t[1005];
int v[100005];
int n, m, num;
bool isok() {
	for (int i = 0; i < num; ++i) {
		int item = t[i];
		if (v[item]) return false;
		v[item] = 1;
		for (auto &e : mp[item]) v[e] = 1;
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	int c1, c2;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &c1, &c2);
		mp[c1].insert(c2);
		mp[c2].insert(c1);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &num);
		memset(v, 0, sizeof(v));
		for (int j = 0; j < num; ++j) scanf("%d", &t[j]);
		if (isok()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}