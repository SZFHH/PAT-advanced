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

long long int mul(int s, int n) {
	long long int rv(1);
	for (int i = s; i < s + n; ++i) rv *= i;
	return rv;
}
int main()
{
	long long int n;
	cin >> n;
	long long int tt = 1, i = 2, maxlen, l, upi(sqrt(n));
	for (; tt <= n; ++i) tt *= i;
	maxlen = i - 3;
	for (l = maxlen; l >= 1; --l) {
		tt = mul(2, l);
		for (i = 3; i<=upi && tt < n && n%tt; ++i) tt = tt / (i - 1)*(i + l - 1);
		if (n%tt == 0) break;
	}
	i--;
	if (l == 0) {
		i = n;
		l = 1;
	}
	cout << l << endl;
	for (long long int x = i; x < i + l; ++x) {
		if (x != i) cout << '*';
		cout << x;
	}
	return 0;
}