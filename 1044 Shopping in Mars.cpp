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

int a[100005];
vector<pair<int, int>> ans;
int cur = 1, n, m;
bool find_(int diff) {
	while (a[cur] < diff) cur++;
	if (a[cur] == diff) return true;
	else return false;
}
int main()
{
	cin >> n >> m;
	int close = INT_MAX;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 2; i <= n; ++i) a[i] += a[i - 1];
	for (int j = 1; j <= n; ++j) {
		int i;
		if (a[j] < m) continue;
		else if (a[j] == m) i = 0;
		else {
			if (find_(a[j] - m)) i = cur;
			else i = cur - 1;
		}
		if (a[j] - a[i] < close) {
			close = a[j] - a[i];
			ans.clear();
			ans.push_back(make_pair(i+1, j));
		}
		else if (a[j] - a[i] == close) ans.push_back(make_pair(i+1, j));
	}
	for (auto &p : ans) printf("%d-%d\n", p.first, p.second);	
	return 0;
}