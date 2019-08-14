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
int lo, hi;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	lo = 0, hi = n - 1;
	while (lo < hi) {
		if (2 * a[lo] > m) break;
		while (a[hi] > m - a[lo]) hi--;
		if (hi!=lo && a[hi] == m - a[lo]) {
			cout << a[lo] << ' ' << a[hi];
			return 0;
		}
		lo++;
	}
	cout << "No Solution";
	return 0;
}