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
struct node{
	node* left, *right;
	int data;
	node(int data_):data(data_),left(nullptr),right(nullptr){}
};
struct bt {
	node*  root;
	bt() :root(nullptr) {}
	node* insert_(int data, node* nd) {
		if (nd == nullptr) return new node(data);
		if (data < nd->data) nd->left = insert_(data, nd->left);
		else nd->right = insert_(data, nd->right);
		return nd;
	}
	void insert(int data) { root = insert_(data, root); }
	void show() {
		queue<node*> q;
		q.push(root);
		printf("%d", q.front()->data);
		while (!q.empty()) {
			node* cur = q.front();
			q.pop();
			if (cur->left) {
				printf(" %d", cur->left->data);
				q.push(cur->left);
			}
			if (cur->right) {
				printf(" %d", cur->right->data);
				q.push(cur->right);
			}
		}
	}

};
bt tree;
vector<int> v;
void buildtree(int lo, int hi) {
	if (lo > hi) return;
	int tt = hi - lo + 1, i, leftnum;
	i = log2(tt);
	leftnum = tt >= 3 * pow(2, i - 1) - 1 ? pow(2, i) - 1 : tt - pow(2, i - 1);
	tree.insert(v[lo + leftnum]);
	buildtree(lo, lo + leftnum - 1);
	buildtree(lo + leftnum + 1, hi);
}
int main()
{
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	buildtree(0, n - 1);
	tree.show();
	return 0;
}