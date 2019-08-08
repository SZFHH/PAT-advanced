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
#include<limits.h>
#include<queue>
using namespace std;

double mid[2005];
double rv[2005];
double mul1[2005];
double mul2[2005];
void setzero(double arr[]) {
	for (int i = 0; i < 2005; ++i)
		arr[i] = 0;
}
void multi(double arr[], int e, double c) {
	for (int i = 0; i < 2005; i++) {
		if (abs(arr[i]) > 1e-7) {
			mid[i + e] += arr[i] * c;
		}
	}
}
void plus_m(double des[], double src[]) {
	for (int i = 0; i < 2005; ++i) {
		des[i] += src[i];
	}
}
int main()
{
	setzero(mid);
	setzero(rv);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp1;
		double tmp2;
		cin >> tmp1 >> tmp2;
		mul1[tmp1] = tmp2;
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp1;
		double tmp2;
		cin >> tmp1 >> tmp2;
		mul2[tmp1] = tmp2;
	}
	for (int i = 0; i < 2005; ++i) {

		if (abs(mul1[i]) > 1e-7) {
			multi(mul2, i, mul1[i]);
			plus_m(rv, mid);
			setzero(mid);
		}
	}
	int ct = 0;
	for (int i = 0; i < 2005; ++i) {
		if (abs(rv[i]) > 1e-7) {
			ct++;
		}
	}
	cout << ct;
	cout << fixed << setprecision(1);
	for (int i = 2004; i >= 0; --i) {
		if (abs(rv[i]) > 1e-7) {
			cout << ' ' << i << ' ' << rv[i];
		}
	}

	return 0;
}
