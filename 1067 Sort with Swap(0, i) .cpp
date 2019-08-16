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
int v[100005];
int main()
{
	int n, cct=0, isz = 0, ct=0;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	if (a[0] == 0) isz = 1;
	for (int i = 0; i < n; ++i) {
		if (v[i]) continue;
		if (a[i] == i) ct++;
		int s = a[i], j = a[i];
		while (a[j] != s) {
			v[j] = true;
			j = a[j];
		}
		cct++;
	}
	cct -= ct;
	if (isz) cout << n + cct - ct;
	else cout << n + cct - ct - 2;
	return 0;
}