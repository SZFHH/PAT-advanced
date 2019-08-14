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

int a[10005];
int ans[10005];
int order[205];
int main()
{
	int n, m, l, tmp;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) order[i] = INT_MAX;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &tmp);
		order[tmp] = i;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; ++i) cin >> a[i];
	for (int i = 0; i < l; ++i) {
		if (order[a[i]]==INT_MAX) continue;
		int maxnum = 0;
		for (int j = 0; j < i; ++j) {
			if (order[a[j]] <= order[a[i]] && ans[j]>maxnum) maxnum = ans[j];
		}
		ans[i] = maxnum + 1;
	}
	printf("%d", *max_element(ans, ans + l));
	return 0;
}