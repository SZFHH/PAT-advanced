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
	int data, index;
	bool operator<(node & n) {
		return index < n.index;
	}
};
vector<node> l2r, r2l;
int in[35], post[35];
int n;
void pre(int root, int left, int right, int index) {
	if (left > right) return;
	int i = left;
	while (i < right && in[i] != post[root]) ++i;
	l2r.push_back(node{ post[root],index });
	pre(root + i - right - 1, left, i - 1, index * 2);
	pre(root - 1, i + 1, right, index * 2 + 1);
}
void pre2(int root, int left, int right, int index) {
	if (left > right) return;
	int i = left;
	while (i < right && in[i] != post[root]) ++i;
	r2l.push_back(node{ post[root],index });
	pre2(root - 1, i + 1, right, index * 2);
	pre2(root + i - right - 1, left, i - 1, index * 2 + 1);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> in[i];
	for (int i = 0; i < n; ++i) cin >> post[i];
	pre(n - 1, 0, n - 1, 1);
	pre2(n - 1, 0, n - 1, 1);
	sort(l2r.begin(), l2r.end());
	sort(r2l.begin(), r2l.end());
	bool r = true;
	for (int j = 0; j < n;) {
		int e = j;
		while (l2r[j].data != r2l[e].data) ++e;
		if (r) {
			for (int k = j; k <= e; ++k) {
				if (k != 0) cout << ' ';
				cout << r2l[k].data;
			}
		}
		else {
			for (int k = j; k <= e; ++k) {
				if (k != 0) cout << ' ';
				cout << l2r[k].data;
			}
		}
		j = e + 1;
		r = !r;
	}
	return 0;
}