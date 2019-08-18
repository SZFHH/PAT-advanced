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
long int a[100005];
int main()
{
	int n, p, curmax = 0;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n - curmax; ++i) {
		long int require = a[i] * p;
		for (int j = i + curmax; j < n; ++j) {
			if (a[j] <= require) curmax = max(curmax, j - i + 1);
			else break;
		}
	}
	cout << curmax;
	return 0;
}