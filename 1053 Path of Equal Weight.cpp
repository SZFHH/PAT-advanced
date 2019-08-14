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

struct node {
	int w;
	vector<int> ch;
};
vector<node> tree;
bool cmp(int chd1, int chd2) {
	return tree[chd1].w > tree[chd2].w;
}
int n, m, s;
int curw;
vector<int> path;
void DST(int nd) {
	if (curw == s && !tree[nd].ch.size()) {
		for (int i = 0; i < path.size(); ++i) {
			if (i != 0) cout << ' ';
			cout << tree[path[i]].w;
		}
		cout << endl;
		return;
	}
	if (curw > s) return;
	for (auto &c : tree[nd].ch) {
		path.push_back(c);
		curw += tree[c].w;
		DST(c);
		curw -= tree[c].w;
		path.pop_back();
	}
}
int main()
{
	cin >> n >> m >> s;
	tree.resize(n);
	for (int i = 0; i < n; ++i) cin >> tree[i].w;
	for (int i = 0; i < m; ++i) {
		int par, num, chd;
		cin >> par >> num;
		for (int i = 0; i < num; ++i) {
			cin >> chd;
			tree[par].ch.push_back(chd);
			sort(tree[par].ch.begin(), tree[par].ch.end(), cmp);
		}
	}
	path.push_back(0);
	curw += tree[0].w;
	DST(0);
	return 0;
}