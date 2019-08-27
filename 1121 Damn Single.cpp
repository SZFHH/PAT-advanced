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
map<int, int> cp;
vector<int> ans;
int arr[10005], ct[100005];
int main()
{
	int n, m, p1, p2;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p1, &p2);
		cp[p1] = p2;
		cp[p2] = p1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &p1);
		arr[i] = p1;
		ct[p1]++;
		if (ct[cp[p1]]) {
			ct[cp[p1]]++;
			ct[p1]++;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (ct[arr[i]] == 1) ans.push_back(arr[i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		if (i != 0) printf(" ");
		printf("%05d", ans[i]);
	}
	return 0;
}