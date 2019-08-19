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
vector<vector<int>> tree;
int main()
{
	int n, par, root;
	double p, r;
	cin >> n >> p >> r;
	tree.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> par;
		if(par!=-1) tree[par].push_back(i);
		else root = i;
	}
	queue<int> q;
	q.push(root);
	int last(root), tmplast, le(0), ct(0), curct(1), lastct(0);
	while (!q.empty()) {
		par = q.front();
		q.pop();
		for (auto &chd : tree[par]) {
			q.push(chd);
			tmplast = chd;
			ct++;
		}
		if (last == par) {
			le++;
			last = tmplast;
			lastct = curct;
			curct= ct;
			ct = 0;
		}
	}
	printf("%.2f %d", p*pow(1 + r / 100, le-1), lastct);
	return 0;
}