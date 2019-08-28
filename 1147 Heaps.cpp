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
int m, n;
int h[1005];
vector<int> ans;
bool ismaxh(int rt) {
	if (rt >= n) return true;
	if ((rt * 2 + 1 < n && h[rt] < h[rt * 2 + 1]) || (rt * 2 + 2 < n&&h[rt] < h[rt * 2 + 2])) return false;
	if (!ismaxh(rt * 2 + 1)) return false;
	if (!ismaxh(rt * 2 + 2)) return false;
	return true;
}
bool isminh(int rt) {
	if (rt >= n) return true;
	if ((rt * 2 + 1 < n && h[rt] > h[rt * 2 + 1]) || (rt * 2 + 2 < n&&h[rt] > h[rt * 2 + 2])) return false;
	if (!isminh(rt * 2 + 1)) return false;
	if (!isminh(rt * 2 + 2)) return false;
	return true;
}
void post(int rt) {
	if (rt >= n) return;
	post(rt * 2 + 1);
	post(rt * 2 + 2);
	ans.push_back(h[rt]);
}
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &h[j]);
		if (ismaxh(0)) printf("Max Heap\n");
		else if (isminh(0)) printf("Min Heap\n");
		else printf("Not Heap\n");
		post(0);
		for (int i = 0; i < ans.size(); ++i) {
			if (i != 0) printf(" ");
			printf("%d", ans[i]);
		}
		putchar('\n');
		ans.clear();
	}
	return 0;
}