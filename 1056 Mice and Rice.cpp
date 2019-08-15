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

int m_rank[1005];
int gd[1005];
vector<int> gp;
int main()
{
	int n, m, cur(0);
	cin >> n >> m;
	gp.resize(n);
	for (int i = 0; i < n; ++i) cin >> gd[i];
	for (int i = 0; i < n; ++i) cin >> gp[i];
	while (gp.size()-cur>1) {
		int len = gp.size();
		int rk = ceil(double(len - cur) / m) + 1;
		for (int i = cur; i < len; i+=m) {
			int end = i + m <= len ? i + m : len;
			int maxgd = -1;
			for (int s = i; s < end; ++s) maxgd = max(gd[gp[s]], maxgd);
			for (int s = i; s < end; ++s) {
				if (gd[gp[s]] != maxgd) m_rank[gp[s]] = rk;
				else gp.push_back(gp[s]);
			}
		}
		cur = len;
	}
	m_rank[gp[cur]] = 1;
	for (int i = 0; i < n; ++i) {
		if (i != 0) cout << ' ';
		cout << m_rank[i];
	}
	return 0;
}