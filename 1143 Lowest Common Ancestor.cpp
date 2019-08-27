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
	node* left, *right, *par;
	int data, h;
	node() :left(nullptr), right(nullptr), par(nullptr), data(0), h(0){}
};
int ct;
node alln[10005];
struct tree {
	node* root, *hot;
	node* find_(int data) {
		node* p = root;
		hot = p;
		while (p) {
			hot = p;
			if (data < p->data) p = p->left;
			else if (data > p->data)p = p->right;
			else break;
		}
		return p;
	}
	node* getnode(int data, node* par, int h) {
		alln[ct].data = data;
		alln[ct].par = par;
		alln[ct].h = h;
		ct++;
		return alln + ct - 1;
	}
	void insert(int data) {
		if (root == nullptr) root = getnode(data, nullptr, 0);
		else {
			find_(data);
			if (data < hot->data) hot->left = getnode(data, hot, hot->h + 1);
			else if (data > hot->data) hot->right = getnode(data, hot, hot->h + 1);
		}
	}
	int lca(node* pu, node* pv) {
		while (pu != pv) {
			if (pu->h > pv->h) pu = pu->par;
			else pv = pv->par;
		}
		return pu->data;
	}
	bool ispar(node* pu, node* pv) {
		while (pu->h < pv->h) pv = pv->par;
		return pv == pu;
	}
	void solve(int u, int v) {
		bool hasu, hasv;
		node* pu = find_(u);
		node* pv = find_(v);
		if (!pu && !pv) printf("ERROR: %d and %d are not found.\n", u, v);
		else if (!pu) printf("ERROR: %d is not found.\n", u);
		else if (!pv) printf("ERROR: %d is not found.\n", v);
		else {
			if (ispar(pv,pu)) printf("%d is an ancestor of %d.\n", v, u);
			else if (ispar(pu, pv)) printf("%d is an ancestor of %d.\n", u, v);
			else printf("LCA of %d and %d is %d.\n", u, v, lca(pu,pv));
		}
	}
	tree() :root(nullptr), hot(nullptr) {}
};

int main()
{
	tree t;
	int n, m, c, u, v;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &c);
		t.insert(c);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &u, &v);
		t.solve(u, v);
	}
	return 0;
}