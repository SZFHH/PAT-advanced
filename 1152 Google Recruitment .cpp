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
bool isprime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	int k = sqrt(n);
	for (int i = 2; i <= k; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int main()
{
	string s;
	int n, m;
	cin >>n >> m >> s;
	for (int i = 0; i <= n - m; ++i) {
		if (isprime(atoi(s.substr(i, m).c_str()))) {
			cout << s.substr(i, m);
			return 0;
		}
	}
	cout << 404;
	return 0;
}