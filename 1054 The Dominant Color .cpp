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

map<int, int> ans;
int main()
{
	int m, n, c;
	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &c);
			ans[c]++;
		}
	}
	int mc, mcare = 0;
	for (auto &c : ans) {
		if (c.second > mcare) {
			mcare = c.second;
			mc = c.first;
		}
	}
	cout << mc;
	return 0;
}