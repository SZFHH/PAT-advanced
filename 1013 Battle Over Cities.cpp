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

struct pa {
	int a, b;
	pa(int i, int j) :a(i), b(j) {};
	pa() :pa(0, 0) {};
	bool isok(int k) { return a != k && b != k; }
};

int a[1005];
int findroot(int k) {
	while (a[k] > 0)
		k = a[k];
	return k;
}
void merge(int rt1, int rt2) {
	if (rt1 != rt2) {
		if (a[rt1] < a[rt2]) {
			a[rt1] += a[rt2] - 1;
			a[rt2] = rt1;
		}
		else {
			a[rt2] += a[rt1] - 1;
			a[rt1] = rt2;
		}
	}
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<pa> rdlist(m);
	for (int i = 0; i < m; ++i)
		scanf("%d%d", &rdlist[i].a, &rdlist[i].b);
		//cin >> rdlist[i].a >> rdlist[i].b;

	for (int i = 0; i < k; ++i) {
		memset(a, 0, sizeof(a));
		int city;
		scanf("%d", &city);
		//cin >> city;
		for (auto &rd : rdlist) {
			if (rd.isok(city)) {
				int rt1(findroot(rd.a)), rt2(findroot(rd.b));
				merge(rt1, rt2);
			}
		}
		int ct = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] <= 0)
				++ct;
		}
		//ct = ct - 2 >= 0 ? ct - 2 : 0;
		printf("%d\n", ct-2);
	}
	return 0;
}