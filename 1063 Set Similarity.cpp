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
vector<set<int>> v;
int main()
{
	int n, m, data, num, s1, s2 ,ct;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &data);
			v[i].insert(data);
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		ct = 0;
		scanf("%d %d", &s1, &s2);
		set<int> &tmps = v[s2 - 1];
		for (auto &e : v[s1 - 1]) {
			if (tmps.find(e) != tmps.end()) ct++;
		}
		printf("%.1f%%\n", ct / double(v[s1 - 1].size() + v[s2 - 1].size() - ct) * 100);
	}
	return 0;
}