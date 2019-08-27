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
vector<int> e;
vector<vector<int>> v;
int n, m, q;
int main()
{
	scanf("%d%d", &n, &m);
	e.resize(m);
	v.resize(n);
	int c1, c2;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &c1, &c2);
		v[c1].push_back(i);
		v[c2].push_back(i);
	}
	scanf("%d", &q);
	int num, c;
	while (q--) {
		for (auto &ed : e) ed = 1;
		scanf("%d", &num);
		for (int i = 0; i < num; ++i) {
			scanf("%d", &c);
			for (auto &ed : v[c]) e[ed] = 0;
		}
		if (accumulate(e.begin(), e.end(), 0)) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}