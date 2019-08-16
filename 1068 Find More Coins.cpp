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
bool dp[105][10005];
bool v[105][10005];
int a[10005];
vector<int> ans;
int findfirst(bool arr[], int size) {
	for (int i = size; i >= 0 ; --i) {
		if (arr[i]) return i;
	}
	return 0;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 0; i <= n; ++i) dp[0][i] = true;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[j] > i) {
				dp[i][j] = dp[i][j - 1];
			}
			else {
				dp[i][j] = dp[i - a[j]][j - 1] || dp[i][j - 1];
				if (dp[i - a[j]][j - 1]) v[i][j] = true;
			}
		}
	}
	while (m) {
		int i = findfirst(v[m], n);
		n = i - 1;
		if (!i) {
			printf("No Solution\n");
			break;
		}
		ans.push_back(a[i]);
		m -= a[i];
	}
	for (int i = 0; i < ans.size(); ++i) {
		if (i) cout << ' ';
		cout << ans[i];
	}
	return 0;
}