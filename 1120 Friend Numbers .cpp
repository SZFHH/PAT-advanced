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
int ans[50];
int cal(int n) {
	int sum = 0, k = 1000;
	while (k >= 1) {
		sum += n / k;
		n %= k;
		k /= 10;
	}
	return sum;
}
vector<int> a;
int main()
{
	int n, num, ct = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		ans[cal(num)] = 1;
	}
	for (int i = 0; i < 50; ++i) {
		if (ans[i]) {
			ct++;
			a.push_back(i);
		} 
	}
	cout << ct << endl;
	for (int i = 0; i < a.size(); ++i) {
		if (i != 0) cout << ' ';
		cout << a[i];
	}
	return 0;
}