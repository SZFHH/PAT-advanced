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

vector<int> num;
long long int last[15];
int main()
{
	long long int n, sum(0), n2;
	cin >> n;
	n2 = n;
	for (int i = 1e9; i > 0; i /= 10) {
		num.push_back(n2 / i);
		n2 %= i;
	}
	for (int i = 1; i <= 9; ++i) last[i] = 10 * last[i - 1] + pow(10, i-1);
	reverse(num.begin(), num.end());
	for (int i = 0; i < num.size();++i) {
		if (num[i] > 1) sum += num[i] * last[i] + pow(10, i);
		else if (num[i] == 1) sum += num[i] * last[i] + n%int(pow(10, i)) + 1;
	}
	cout << sum;
	return 0;
}