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

bool ispalin(vector<int> & s) {
	int len = s.size() / 2;
	for (int i = 0; i < len; ++i) {
		if (s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}
vector<int> torad(int n, int radix) {
	vector<int> tmp;
	while (n >= radix) {
		tmp.push_back(n%radix);
		n /= radix;
	}
	tmp.push_back(n);
	reverse(tmp.begin(), tmp.end());
	return tmp;
}
int main()
{
	int n, r;
	cin >> n >> r;
	vector<int> rv = torad(n, r);
	if (ispalin(rv))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << rv[0];
	for (int i = 1; i < rv.size(); ++i)
		cout << ' ' << rv[i];
	return 0;
}