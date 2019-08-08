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

long long int cal(const string & s, long long int rdx) {
	long long int sum = 0;
	for (auto it = s.begin(); it != s.end(); ++it) {
		char k = *it;
		long long int dig = isdigit(k) ? k - '0' : k - 'a' + 10;
		sum = sum*rdx + dig;
	}
	return sum;
}

int fimdminrx(const string &s) {
	int m = 0;
	for (auto & i : s) {
		if (isdigit(i))
			m = max(m, i - '0');
		else
			m = max(m, i - 'a' + 10);

	}
	/*if (m == 0)
	return 2;*/
	return m + 1;
}
bool allzero(string & s) {
	for (auto & i : s) {
		if (i != '0')
			return false;
	}
	return true;
}
int main()
{
	string n1, n2;
	long long int k, radix;
	cin >> n1 >> n2 >> k >> radix;

	if (k == 2)
		n1.swap(n2);
	if (allzero(n2) && !allzero(n1))
	{
		cout << "Impossible";
		return 0;
	}
	long long int rv = fimdminrx(n2);
	long long int int_n1 = cal(n1, radix);
	long long int lo = rv, hi = int_n1, mid = rv;
	if (cal(n2, rv) < int_n1) {
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			long long int tmp = cal(n2, mid);
			if (tmp<0 || tmp>int_n1)
				hi = mid - 1;
			else if (tmp < int_n1)
				lo = mid + 1;
			else
				break;
		}
	}
	rv = mid;
	if (cal(n2, rv) == int_n1)
		cout << rv;
	else
		cout << "Impossible";

	return 0;
}
