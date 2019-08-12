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

queue<int>a, b;
int main()
{
	int n, m, tmp, ct = 0;
	cin >> n;
	for (int i = 0; i < n; ++i){
		scanf("%d", &tmp);
		a.push(tmp);
	}
	a.push(INT_MAX);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &tmp);
		b.push(tmp);
		if (ct == (n + m - 1) / 2) {
			cout << min(a.front(), b.front());
			return 0;
		}
		if (a.front() < b.front()) a.pop();
		else b.pop();
		ct++;
	}
	b.push(INT_MAX);
	for (; ct < (n + m - 1) / 2; ++ct) {
		if (a.front() < b.front()) a.pop();
		else b.pop();
	}
	cout << min(a.front(), b.front());
	return 0;
}