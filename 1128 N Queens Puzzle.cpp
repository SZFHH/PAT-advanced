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
	int c, r;
	bool operator==(node &n) {
		return n.r == r || abs(r - n.r) == abs(c - n.c);
	}
};
vector<node> v;
bool isok() {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			if (v[i] == v[j]) return false;
		}
	}
	return true;
}
int main()
{
	int n, m, r;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		for (int j = 1; j <= m; ++j) {
			cin >> r;
			v.push_back(node{ j,r });
		}
		if (isok()) cout << "YES" << endl;
		else cout << "NO" << endl;
		v.clear();
	}
	return 0;
}