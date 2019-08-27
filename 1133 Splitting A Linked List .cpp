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
int m_next[100005], m_data[100005];
vector<int> ans, lis;
int n, fadd, k;
bool cmp(int i, int j) {
	if (m_data[i] < 0 && m_data[j] >= 0) return true;
	if (m_data[i] >= 0 && m_data[i] <= k && m_data[j] > k) return true;
	return false;
}
int main()
{
	scanf("%d%d%d", &fadd, &n, &k);
	int add;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &add);
		scanf("%d%d", &m_data[add], &m_next[add]);
	}
	while (fadd != -1) {
		ans.push_back(fadd);
		fadd = m_next[fadd];
	}
	stable_sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size() - 1; ++i) {
		printf("%05d %d %05d\n", ans[i], m_data[ans[i]], ans[i + 1]);
	}
	printf("%05d %d %d\n", ans[ans.size()-1], m_data[ans[ans.size()-1]], -1);
	return 0;
}