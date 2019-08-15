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
int n;
bool allzero(string &s) {
	for (auto &c : s) {
		if (c != '.' && c != '0') return false;
	}
	return true;
}
int trans(string & s) {
	string rv = "0.";
	if (allzero(s)) {
		rv += string(n, '0');
		s = rv;
		return 0;
	}
	int dotpos = 0, f, ct = 0, i = 0;
	while (dotpos < s.size() && s[dotpos] != '.')++dotpos;
	while (s[i]=='.' || s[i] == '0') ++i;
	f = dotpos - i;
	if (f < 0) f++;
	for (; ct < n && i < s.size(); ++i) {
		if (s[i] != '.') {
			rv.push_back(s[i]);
			ct++;
		} 
	}
	s = rv;
	return f;
}
int main()
{
	string s1, s2;
	cin >> n >> s1 >> s2;
	int f1, f2;
	f1 = trans(s1);
	f2 = trans(s2);
	if (s1 == s2 && f1 == f2) cout << "YES" << ' ' << s1 << "*10^" << f1;
	else cout << "NO" << ' ' << s1 << "*10^" << f1 << ' ' << s2 << "*10^" << f2;
	return 0;
}