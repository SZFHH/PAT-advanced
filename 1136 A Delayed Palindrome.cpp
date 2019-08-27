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
string adds(string &s1, string &s2) {
	string rv;
	int last = 0;
	for (int i = s1.size() - 1; i >= 0; --i) {
		int tmp = s1[i] + s2[i] - '0' - '0' + last;
		last = tmp / 10;
		tmp %= 10;
		rv.push_back(tmp + '0');
	}
	if (last) rv.push_back('1');
	reverse(rv.begin(), rv.end());
	return rv;
}
bool ispalin(string &s) {
	int len = s.size() / 2;
	for (int i = 0; i < len; ++i) {
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}
int main()
{
	string s1, s2, ans;
	cin >> ans;
	int k = 10;
	while (k-- && !ispalin(ans)) {
		s1 = ans;
		s2.resize(s1.size());
		reverse_copy(s1.begin(), s1.end(), s2.begin());
		ans = adds(s1, s2);
		printf("%s + %s = %s\n", s1.c_str(), s2.c_str(), ans.c_str());
	}
	if (ispalin(ans)) printf("%s is a palindromic number.\n", ans.c_str());
	else printf("Not found in 10 iterations.\n");
	return 0;
}