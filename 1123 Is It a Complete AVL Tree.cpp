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
vector<int> ans;
struct node {
	node* left, *right;
	int data, height, index;
	node(int data_):data(data_),height(1), left(nullptr),right(nullptr){}
};
struct avltree {
	node* root;
	avltree():root(nullptr){}
	int height(node* nd) {
		if (nd) return nd->height;
		else return 0;
	}
	node* LL(node* nd) {
		node* tmp = nd->left;
		nd->left = tmp->right;
		tmp->right = nd;
		nd->height = max(height(nd->left), height(nd->right)) + 1;
		tmp->height = max(height(tmp->left), nd->height) + 1;
		return tmp;
	}
	node* RR(node* nd){
		node* tmp = nd->right;
		nd->right = tmp->left;
		tmp->left = nd;
		nd->height = max(height(nd->left), height(nd->right)) + 1;
		tmp->height = max(height(tmp->right), nd->height) + 1;
		return tmp;
	}
	node* LR(node* nd) {
		nd->left = RR(nd->left);
		return LL(nd);
	}
	node* RL(node* nd) {
		nd->right = LL(nd->right);
		return RR(nd);
	}
	node* insert_(int data, node* nd) {
		if (nd == nullptr) return new node(data);
		if (data < nd->data) {
			nd->left = insert_(data, nd->left);
			if (height(nd->left) - height(nd->right) > 1) {
				if (data < nd->left->data) nd = LL(nd);
				else nd = LR(nd);
			}
		}
		else {
			nd->right = insert_(data, nd->right);
			if (height(nd->right) - height(nd->left) > 1) {
				if (data > nd->right->data) nd = RR(nd);
				else nd = RL(nd);
			}
		}
		nd->height = max(height(nd->left), height(nd->right)) + 1;
		return nd;
	}
	void insert(int data) { root = insert_(data, root); }
	int level() {
		int maxindex = 1;
		queue<node*> q;
		root->index = 1;
		q.push(root);
		while(!q.empty()){
			node* cur = q.front();
			q.pop();
			ans.push_back(cur->data);
			if (cur->left) {
				cur->left->index = cur->index * 2;
				maxindex = max(maxindex, cur->left->index);
				q.push(cur->left);
			}
			if (cur->right) {
				cur->right->index = cur->index * 2 + 1;
				maxindex = max(maxindex, cur->right->index);
				q.push(cur->right);
			}
		}
		return maxindex;
	}
};
int main()
{
	avltree t;
	int n, num, index;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		t.insert(num);
	}
	index = t.level();
	for (int i = 0; i < n; ++i) {
		if (i != 0) cout << ' ';
		cout << ans[i];
	}
	cout << endl;
	if (index == n) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}