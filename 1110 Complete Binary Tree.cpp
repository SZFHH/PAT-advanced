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
int tree[25][2];
int ntroot[25];
int n, root, maxindex, lastone;
void dst(int rt, int index) {
	if (index == n - 1) lastone = rt;
	if (index > maxindex) maxindex = index;
	if (tree[rt][0] != -1) dst(tree[rt][0], 2 * index + 1);
	if (tree[rt][1] != -1) dst(tree[rt][1], 2 * index + 2);
}
int main()
{	
	string c1, c2;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c1 >> c2;
		if (c1 != "-") {
			tree[i][0] = atoi(c1.c_str());
			ntroot[atoi(c1.c_str())] = 1;
		}
		else tree[i][0] = -1;
		if (c2 != "-") {
			tree[i][1] = atoi(c2.c_str());
			ntroot[atoi(c2.c_str())] = 1;
		}
		else tree[i][1] = -1;
	}
	while (ntroot[root]) ++root;
	dst(root, 0);
	if (maxindex == n-1) printf("YES %d", lastone);
	else printf("NO %d", root);
	return 0;
}