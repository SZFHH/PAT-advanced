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
#include<set>
#include<limits.h>
#include<queue>
using namespace std;

int level[105];
int haschild[105];
int parent[105];
int main()
{

	int n, m;
	while (cin >> n >> m) {
		level[1] = 1;
		int maxlevel = 1;
		memset(level, 0, sizeof(0));
		memset(haschild, 0, sizeof(0));
		for (int i = 0; i < m; ++i) {
			int par, nums;
			cin >> par >> nums;
			haschild[par] = 1;
			for (int i = 0; i < nums; ++i) {
				int child;
				cin >> child;
				parent[child] = par;
			}
		}
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int par = q.front();
			q.pop();
			for (int i = 0; i < 105; ++i) {
				if (parent[i] == par) {
					level[i] = level[par] + 1;
					q.push(i);
				}
			}
		}
		maxlevel = *max_element(level, level + 105);
		bool isfirst = true;
		for (int i = 1; i <= maxlevel; ++i) {

			int tt = 0;
			for (int j = 0; j < 105; ++j) {
				if (level[j] == i && !haschild[j])
					++tt;
			}
			if (isfirst) {
				cout << tt;
				isfirst = false;
			}
			else
				cout << ' ' << tt;
		}
	}
	return 0;
}
