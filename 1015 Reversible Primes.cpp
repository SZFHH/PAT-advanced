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

bool isprime(int n) {
	if (n == 2)
		return true;
	if (n == 1)
		return false;
	int k = sqrt(n);
	for (int i = 2; i <= k; ++i) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int cal(const string & s, int radix) {
	int sum = 0;
	for (auto &c : s) {
		sum = sum*radix + c - '0';
	}
	return sum;
}
string toradix(int n, int radix) {
	string tmp;
	while (n) {
		tmp.push_back(n%radix + '0');
		n /= radix;
	}
	return tmp;
}
int main()
{
	int a, b;
	string s;
	int radix;
	while (1) {
		cin >> s;
		if (s[0] == '-')
			break;
		cin >> radix;
		a = cal(s, 10);
		s = toradix(a, radix);
		b = cal(s, radix);
		if (isprime(a) && isprime(b))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}