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
int n, m, ao, al, bo, bl;
vector<int> a, b;
int main()
{
	long long int sum = 0;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > 0) ao++;
		if (a[i] < 0) al++;
	}
	cin >> m;
	b.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		if (b[i] > 0) bo++;
		if (b[i] < 0) bl++;
	}
	int mino = min(ao, bo), minl = min(al, bl);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < minl; ++i) sum += a[i] * b[i];
	for (int i = 0; i < mino; ++i) sum += a[a.size() - 1 - i] * b[b.size() - 1 - i];
	cout << sum;
	return 0;
}