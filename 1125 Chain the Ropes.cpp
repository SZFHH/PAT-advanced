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

int main()
{
	priority_queue<double, vector<double>, greater<double>> q;
	int n;
	double r, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> r;
		q.push(r);
	}
	while (q.size() > 1) {
		double r1, r2;
		r1 = q.top();
		q.pop();
		r2 = q.top();
		q.pop();
		q.push((r1 + r2) / 2);
	}
	cout << int(q.top());
	return 0;
}