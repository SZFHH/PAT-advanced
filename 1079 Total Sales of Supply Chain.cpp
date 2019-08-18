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
	vector<int> child;
	double price, tt;
};
int n;
double p, r, sum(0);
vector<node> v;
int main()
{
	cin >> n >> p >> r;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		int num, tid;
		cin >> num;
		if (!num) {
			cin >> tid;
			v[i].tt = tid;
		} 
		for (int j = 0; j < num; ++j) {
			cin >> tid;
			v[i].child.push_back(tid);
		}
	}
	v[0].price = p;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (!v[cur].child.size()) sum += v[cur].tt*v[cur].price;
		for (auto &c : v[cur].child) {
			v[c].price = v[cur].price*(1 + r / 100);
			q.push(c);
		}
	}
	printf("%.1f", sum);
	return 0;
}
