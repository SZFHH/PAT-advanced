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
int m_next[100005];
int m_data[100005];
vector<int> ans;
bool cmp(int ad1, int ad2) {
	return m_data[ad1] < m_data[ad2];
}
int main()
{
	int n, fadd, add;
	cin >> n >> fadd;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &add);
		scanf("%d%d", &m_data[add], &m_next[add]);
	}
	while (fadd != -1) {
		ans.push_back(fadd);
		fadd = m_next[fadd];
	}
	if (ans.size()) {
		sort(ans.begin(), ans.end(), cmp);
		printf("%d %05d\n", ans.size(), ans[0]);
		for (int i = 0; i < ans.size() - 1; ++i)
			printf("%05d %d %05d\n", ans[i], m_data[ans[i]], ans[i + 1]);
		printf("%05d %d %d\n", ans[ans.size() - 1], m_data[ans[ans.size() - 1]], -1);
	}
	else printf("%d %d\n", ans.size(), -1);
	return 0;
}