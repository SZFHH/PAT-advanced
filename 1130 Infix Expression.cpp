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
struct node {
	int left, right;
	string data;
	bool issyb() {
		return left != -1 || right != -1;
	}
};
vector<node> tree;
string ans;
int n;
int notrt[25];
void inorder(int rt) {
	if (tree[rt].issyb()) ans.push_back('(');
	if (tree[rt].left != -1) inorder(tree[rt].left);
	ans += tree[rt].data;
	if (tree[rt].right != -1) inorder(tree[rt].right);
	if (tree[rt].issyb()) ans.push_back(')');
}
int main()
{
	cin >> n;
	string data;
	int c1, c2, root = 1;
	tree.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> tree[i].data >> tree[i].left >> tree[i].right;
		notrt[tree[i].left] = 1;
		notrt[tree[i].right] = 1;
	}
	while (notrt[root]) ++root;
	inorder(root);
	if(ans.size()>1) 
		ans = ans.substr(1, ans.size() - 2);
	cout << ans;
	return 0;
}