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

map<long int, long int> ans;
bool isprime(long int n) {
	if (n == 2) return true;
	if (n == 1) return false;
	long int k = sqrt(n);
	for (long int i = 2; i <= k; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int main()
{
	long int n, m;
	cin >> n;
	m = n;
	if (n == 1) {
		cout << "1=1";
		return 0;
	}
    if(isprime(n)){
        cout<<n<<'='<<n;
        return 0;
    }
 	for (long int i = 2; i <= n; ++i) {
		if (n%i ||!isprime(i)) continue;
		while (n%i == 0) {
			n /= i;
			ans[i]++;
		}
	}
	cout << m << '=';
	bool isfirst = true;
	for (auto &s:ans) {
		if (isfirst) {
			cout << s.first;
			if (s.second > 1) cout << '^' << s.second;
			isfirst = false;
		}
		else{
			cout << '*';
			cout << s.first;
			if (s.second > 1) cout << '^' << s.second;
		}
	}
	return 0;
}