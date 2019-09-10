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
int n1=0,n2=1;
struct node {
	node* left, *right;
	int data;
	node(int data_) :data(data_), left(nullptr), right(nullptr) {}
};
struct btree {
	node* root;
	node* insert_(int data, node* nd) {
		if (nd == nullptr) return new node(data);
		if (data <= nd->data) nd->left = insert_(data, nd->left);
		else nd->right = insert_(data, nd->right);
		return nd;
	}
	void insert(int data) { root = insert_(data, root); }
	void levelorder() {
		queue<node*> q;
		q.push(root);
		node* last = root, *tmplast;
		int ct(0);
		while (!q.empty()) {
			node* cur = q.front();
			q.pop();
			if (cur->left) {
				q.push(cur->left);
				ct++;
				tmplast = cur->left;
			}
			if (cur->right) {
				q.push(cur->right);
				ct++;
				tmplast = cur->right;
			}
			if (last == cur) {
                if(ct==0) break;
                n1=n2;
                n2=ct;
				last = tmplast;
				ct = 0;
			}
		}
	}
	btree() :root(nullptr){}
};
int main()
{
	int n, num;
	cin >> n;
	btree t;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		t.insert(num);
	}
	t.levelorder();
	cout << n2 << " + " << n1 << " = " << n1 + n2;
	return 0;
}