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

int graph[505][505];
int cur_cap[505];
int visited[505];
vector<int> path, minpath;
int minlen(INT_MAX), minmvcost(INT_MAX), minmvbkcost(INT_MAX);
int ttlen(0), mvcost(0), mvbkcost(0);
int require_cap, n, sp, m;
void FDT(int s);

int main()
{
	cin >> require_cap >> n >> sp >> m;
	require_cap /=  2;
	for (int i = 1; i <= n; ++i)
		cin >> cur_cap[i];
	for (int i = 0; i < m; ++i) {
		int s1, s2, len;
		cin >> s1 >> s2 >> len;
		graph[s1][s2] = len;
		graph[s2][s1] = len;
	}
	visited[0] = true;
	FDT(0);
	cout << minmvcost << ' ' << 0;
	for (auto &v:minpath) {
		printf("->%d", v);
	}
	cout << ' ' << minmvbkcost;
	return 0;
}

void FDT(int s)
{
	if (s == sp) {
		if (minlen > ttlen || (minlen==ttlen && ( minmvcost> mvcost || (mvcost == minmvcost && minmvbkcost>mvbkcost)))) {
			minlen = ttlen;
			minpath = path;
			minmvbkcost = mvbkcost;
			minmvcost = mvcost;
		}
		return;
	}
	for (int i = 0; i <= n; ++i) {
		if (!visited[i] && graph[s][i]) {
			int tmp1(mvcost), tmp2(mvbkcost);
			ttlen += graph[s][i];
			path.push_back(i);
			mvbkcost += cur_cap[i] - require_cap;
			if (mvbkcost < 0) {
				mvcost -= mvbkcost;
				mvbkcost = 0;
			}
			visited[i] = true;
			FDT(i);
			visited[i] = false;
			ttlen -= graph[s][i];
			path.pop_back();
			mvcost = tmp1, mvbkcost = tmp2;
		}
	}
}