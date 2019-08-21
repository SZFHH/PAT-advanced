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

int n;
double p, r;
vector<vector<int>> tree;
int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	tree.resize(n);
	int num;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		tree[i].resize(num);
		for (int j = 0; j < num; ++j) scanf("%d", &tree[i][j]);
	}
	int le(0), par, ct(0), last(0), tmplast;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		par = q.front();
		q.pop();
		for (auto &chd : tree[par]) {
			tmplast = chd;
			q.push(chd);
		}
		if (!tree[par].size()) ct++;
		if (par == last) {
			if (ct > 0) break;
			le++;
			last = tmplast;
		}
	}
	printf("%.4lf %d", p*pow(1 + r / 100, le), ct);
	return 0;
}