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
int le[100005];
int ri[100005];
vector<int> ans;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	ri[n - 1] = INT_MAX;
	for (int i = n - 1; i >= 1; --i) ri[i - 1] = min(ri[i], arr[i]);
	le[0] = -1;
	for (int i = 0; i <= n - 2; ++i) le[i + 1] = max(le[i], arr[i]);
	for (int i = 0; i < n; ++i) {
		if (arr[i] >= le[i] && arr[i] <= ri[i]) ans.push_back(arr[i]);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	cout << endl;
	return 0;
}