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
int pre[50005], in[50005];
vector<int> ans;
void post(int root, int begin, int end) {
	if (begin > end) return;
	if (ans.size() > 0) return;
	int i = begin;
	while (i < end && in[i] != pre[root]) ++i;
	post(root + 1, begin, i - 1);
	post(i + root - begin + 1, i + 1, end);
	ans.push_back(pre[root]);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
	post(0, 0, n - 1);
	cout << ans[0];
	return 0;
}