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
enum color { black, red };
struct node {
	node* left, *right;
	color c;
	int data;
	node(int data_, color c_) :data(data_), c(c_),left(nullptr),right(nullptr){}
};
struct tree {
	node* root;
	int height;
	node* insert_(int data, node* nd){
		if(!nd) return new node{abs(data),data<0?red:black};
		if (abs(data) < nd->data) nd->left = insert_(data, nd->left);
		else nd->right = insert_(data, nd->right);
		return nd;
	}
	void insert(int data) { root = insert_(data, root); }
	bool isbrt_(node* nd, int h) {
	    int nh = nd->c==red?h:h+1;
		if (!nd->left || !nd->right) {
			if (height == -1) height = nh+1;
			else if (height != nh+1) return false;
		}
		if (nd->c == red) {
			if ((nd->left && nd->left->c == red) || (nd->right && nd->right->c == red)) return false;
		}
		if (nd->left && !isbrt_(nd->left,nh)) return false;
		if (nd->right && !isbrt_(nd->right,nh)) return false;
		return true;
	}
	bool isbrt() {
		if (root->c == red) return false;
		return isbrt_(root, 0);
	}
	void reset() {
		root = nullptr;
		height = -1;
	}
};
int main()
{
	int n, num, c;
	cin >> n;
	tree t;
	while (n--) {
		t.reset();
		cin >> num;
		while (num--) {
			cin >> c;
			t.insert(c);
		}
		if (t.isbrt()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
