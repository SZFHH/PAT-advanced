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
int arr[100005];
int n;
int main()
{	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int k = n / 2, ans;
	ans = abs(accumulate(arr, arr + k, 0) - accumulate(arr + k, arr + n, 0));
	printf("%d %d", n - 2 * k, ans);
	return 0;
}