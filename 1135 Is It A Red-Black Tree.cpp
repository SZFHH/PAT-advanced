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
	int data, height;
	node(int h) :left(nullptr), right(nullptr), c(black), data(0), height(h) {};
	node(int data_, color c_, int h) :data(data_), c(c_), height(h){
		left = new node(h + 1);
		right = new node(h + 1);
	};
};

struct tree {
	node* root;
	int height;
	node* insert_(int data, node* nd, int he){
		if (!nd->data) {
			delete nd;
			color c = black;
			int h = he;
			if (data < 0) {
				c = red;
				data = -data;
			}
			if (c == black) h++;
			return new node(data, c, h);
		}
		if (abs(data) < nd->data) nd->left = insert_(data, nd->left, nd->height);
		else nd->right = insert_(data, nd->right, nd->height);
		return nd;
	}
	void insert(int data) { root = insert_(data, root, 0); }
	bool isbrt_(node* nd) {
		if (!nd->left && !nd->right) {
			if (height == -1) height = nd->height;
			else if (height != nd->height) return false;
		}
		if (nd->c == red) {
			if ((nd->left && nd->left->c == red) || (nd->right && nd->right->c == red)) return false;
		}
		if (nd->left && !isbrt_(nd->left)) return false;
		if (nd->right && !isbrt_(nd->right)) return false;
		return true;
	}
	bool isbrt() {
		if (root->c == red) return false;
		return isbrt_(root); 
	}
	void reset() {
		root = new node(0);
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