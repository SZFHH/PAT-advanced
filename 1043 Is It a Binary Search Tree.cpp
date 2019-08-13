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
	node(int data_) :left(nullptr), right(nullptr), data(data_) {}
};
struct bt {
	node* root;
	node *insert_(int data, node*nd) {
		if (nd == nullptr)
			return new node(data);
		if (data < nd->data)
			nd->left = insert_(data, nd->left);
		else
			nd->right = insert_(data, nd->right);
		return nd;
	}
	
	void insert(int data) {
		root = insert_(data, root);
	}
	void pre_(node *nd, vector<int> &rv, char mode) {
		if (nd) rv.push_back(nd->data);
		if (mode != 'm') {
			if (nd->left) pre_(nd->left, rv, mode);
			if (nd->right) pre_(nd->right, rv, mode);
		}
		else {
			if (nd->right) pre_(nd->right, rv, mode);
			if (nd->left) pre_(nd->left, rv, mode);
		}
		
	}
	void post_(node *nd, vector<int> &rv, char mode) {
		
		if (mode != 'm') {
			if (nd->left) post_(nd->left, rv, mode);
			if (nd->right) post_(nd->right, rv, mode);
		}
		else {
			if (nd->right) post_(nd->right, rv, mode);
			if (nd->left) post_(nd->left, rv, mode);
		}
		if (nd) rv.push_back(nd->data);

	}
	void pre(vector<int> &rv, char mode) {
		pre_(root, rv, mode);
	}
	void post(vector<int> &rv, char mode) {
		post_(root, rv, mode);
	}
	bt() :root(nullptr) {};
};
void show(vector<int> v) {
	for (int i = 0; i < v.size(); ++i) {
		if (i != 0) cout << ' ';
		cout << v[i];
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n), tmp;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	bt t;
	for (auto &i : v)
		t.insert(i);
	t.pre(tmp,'n');
	if (tmp == v) {
		cout << "YES" << endl;
		tmp.clear();
		t.post(tmp,'n');
		show(tmp);
		return 0;
	}
	tmp.clear();
	t.pre(tmp, 'm');
	if (tmp == v) {
		cout << "YES" << endl;
		tmp.clear();
		t.post(tmp, 'm');
		show(tmp);
		return 0;
	}
	cout << "NO";
	return 0;
}