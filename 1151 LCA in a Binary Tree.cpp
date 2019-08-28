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
int in[10005], pre[10005];
map<int, int>num2id, id2num;
int m, n;
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for (int i = 0; i < n; ++i) {
		num2id[in[i]] = i;
		id2num[i] = in[i];
	}
	for (int i = 0; i < n; ++i) pre[i] = num2id[pre[i]];
	int u, v, nu, nv;
	bool fu, fv;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		fu = num2id.find(u) != num2id.end();
		fv = num2id.find(v) != num2id.end();
		if (!fv && !fu) printf("ERROR: %d and %d are not found.\n", u, v);
		else if (!fv) printf("ERROR: %d is not found.\n", v);
		else if (!fu) printf("ERROR: %d is not found.\n", u);
		else {
			nu = num2id[u];
			nv = num2id[v];
			int a;
			for (int k=0; k < n; ++k) {
				a = pre[k];
				if ((a >= nu && a <= nv) || (a <= nu && a >= nv)) break;
			}
			if (a == nu || a == nv) printf("%d is an ancestor of %d.\n", id2num[a], a == nu ? v : u);
			else printf("LCA of %d and %d is %d.\n", u, v, id2num[a]);
		}
	}
	return 0;
}