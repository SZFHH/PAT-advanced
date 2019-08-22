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
int arr[10005];
int hasv[10005];
bool isprime(int n) {
	if (n == 2) return true;
	int k = sqrt(n);
	for (int i = 2; i <= k; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int main()
{
	int n, m, qnum;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> qnum;
		printf("%04d: ", qnum);
		int k = 1;
		for (; k <= n; ++k) {
			if (arr[k] == qnum) break;
		}
		if (k > n) cout << "Are you kidding?" << endl;
		else if (hasv[k]) cout << "Checked" << endl;
		else if (k == 1) cout << "Mystery Award" << endl;
		else if (isprime(k)) cout << "Minion" << endl;
		else cout << "Chocolate" << endl;
		hasv[k] = 1;
	}
	return 0;
}