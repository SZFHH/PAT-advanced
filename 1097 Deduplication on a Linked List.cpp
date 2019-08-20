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

int m_next[100005];
int m_data[100005];
bool isd[10005];
vector<int> not_d, d, ans;
int main()
{
	int start, n, tmp;
	scanf("%d%d", &start, &n);
	if (start == -1) return 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		scanf("%d%d", &m_data[tmp], &m_next[tmp]);
	}
	
	while (start != -1) {
		ans.push_back(start);
		start = m_next[start];
	}
	for (auto &add : ans) {
		if (!isd[abs(m_data[add])]) {
			not_d.push_back(add);
			isd[abs(m_data[add])] = 1;
		}
		else d.push_back(add);
	}
	for (int i = 0; i < not_d.size() - 1; ++i) 
		printf("%05d %d %05d\n", not_d[i], m_data[not_d[i]], not_d[i + 1]);
	printf("%05d %d %d\n", not_d[not_d.size() - 1], m_data[not_d[not_d.size() - 1]], -1);

	for (int i = 0; i < int(d.size()) - 1; ++i) 
		printf("%05d %d %05d\n", d[i], m_data[d[i]], d[i + 1]);
	if(d.size())  printf("%05d %d %d\n", d[d.size() - 1], m_data[d[d.size() - 1]], -1);
	return 0;
}