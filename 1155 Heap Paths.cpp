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
#include<unordered_set>
#include<set>
#include<limits.h>
#include<queue>
#include<stack>
using namespace std;
int n;
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
void dfs(int rt){
	if (rt * 2 >= n - 1) {
		for (int i = 0; i < ans.size(); ++i) {
			if (i != 0) printf(" ");
			printf("%d", ans[i]);
		}
		putchar('\n');
		return;
	}
	int next = rt * 2 + 2;
	if (next < n) {
		ans.push_back(h[next]);
		dfs(next);
		ans.pop_back();
	}
	next = rt * 2 + 1;
	if (next < n) {
		ans.push_back(h[next]);
		dfs(next);
		ans.pop_back();
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
	ans.push_back(h[0]);
	dfs(0);
	if (ismaxh(0)) printf("Max Heap\n");
	else if (isminh(0)) printf("Min Heap\n");
	else printf("Not Heap\n");
	return 0;
}