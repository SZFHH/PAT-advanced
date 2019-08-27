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
int item[50005];
vector<int> ans;
bool cmp(int i, int j) {
	return item[i] == item[j] ? i < j : item[i] > item[j];
}
int main()
{
	int n, m, p, minindex;
	bool hasf = true;
	scanf("%d%d", &n, &m);
	scanf("%d", &p);
	item[p]++;
	minindex = p;
	ans.push_back(p);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &p);
		printf("%d:", p);
		for (auto &a : ans) printf(" %d", a);
		putchar('\n');
		item[p]++;
		hasf = true;
		if (find(ans.begin(), ans.end(), p) == ans.end()) {
			if (ans.size() < m) ans.push_back(p);
			else if (cmp(p, minindex)) ans[ans.size() - 1] = p;
			else hasf = false;
		}
		if (hasf) {
			sort(ans.begin(), ans.end(), cmp);
			minindex = ans[ans.size() - 1];
		}
	}
	return 0;
}