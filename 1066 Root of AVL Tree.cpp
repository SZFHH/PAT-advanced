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
	node* left, *right;
	int data;
	int height;
	node(int data_):data(data_),left(nullptr),right(nullptr),height(1){}
};
int height(node* n1) {
	if (n1) return n1->height;
	else return 0;
}
int hdiff(node* n1, node* n2) {
	return height(n1) - height(n2);
}
struct avlt {
	node* root;
	node* LL(node* nd) {
		node* tmp = nd->left;
		nd->left = tmp->right;
		tmp->right = nd;
		nd->height = max(height(nd->left), height(nd->right)) + 1;
		tmp->height = max(height(tmp->left), nd->height) + 1;
		return tmp;
	}
	node* RR(node * nd) {
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
			if (hdiff(nd->left,nd->right) > 1) {
				if (data < nd->left->data) nd = LL(nd);
				else nd = LR(nd);
			}
		}
		else {
			nd->right = insert_(data, nd->right);
			if (hdiff(nd->right, nd->left) > 1) {
				if (data > nd->right->data) nd = RR(nd);
				else nd = RL(nd);
			}
		}
		nd->height = max(height(nd->left), height(nd->right)) + 1;
		return nd;
	}
	void insert(int data) { 
		root = insert_(data, root); 
	}
	avlt():root(nullptr){}
};
int main()
{
	avlt tree;
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		tree.insert(tmp);
	}
	cout << tree.root->data;
	return 0;
}