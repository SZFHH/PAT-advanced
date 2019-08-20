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

int tree[15][2];
vector<int> in, level;
void inorder(int index) {
	if (tree[index][1] != -1) inorder(tree[index][1]);
	in.push_back(index);
	if (tree[index][0] != -1) inorder(tree[index][0]);
}
void levelorder(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int par = q.front();
		q.pop();
		level.push_back(par);
		if (tree[par][1] != -1) q.push(tree[par][1]);
		if (tree[par][0] != -1) q.push(tree[par][0]);
	}
}
int ntroot[15];
int main()
{
	int n, root(0);
	char c1, c2;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c1 >> c2;
		if (isdigit(c1)) {
			ntroot[c1 - '0'] = 1;
			tree[i][0] = c1 - '0';
		}
		else tree[i][0] = -1;
		if (isdigit(c2)) {
			ntroot[c2 - '0'] = 1;
			tree[i][1] = c2 - '0';
		}
		else tree[i][1] = -1;
	}
	while (ntroot[root]) root++;
	inorder(root);
	levelorder(root);
	for (int i = 0; i < level.size(); ++i) {
		if (i != 0) cout << ' ';
		cout << level[i];
	}
	cout << endl;
	for (int i = 0; i < in.size(); ++i) {
		if (i != 0) cout << ' ';
		cout << in[i];
	}
	return 0;
}