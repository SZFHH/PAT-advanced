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
#include<set>
using namespace std;
int rv[130];
double a[1005];
double b[1005];
int main()
{
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int e;
		double c;
		cin >> e >> c;
		a[e] = c;
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int e;
		double c;
		cin >> e >> c;
		b[e] = c;
	}
	for (int i = 0; i < 1005; ++i) {
		a[i] += b[i];
	}

	int total = 0;
	for (int i = 0; i < 1005; ++i) {
		if (abs(a[i]) > 1e-7)
			total++;
	}
	cout << total;
	cout << fixed << setprecision(1);
	for (int i = 1005; i >= 0; --i) {
		if (abs(a[i]) > 1e-7)
		{
			cout << ' ' << i << ' ' << a[i];
		}
	}

	return 0;
}
