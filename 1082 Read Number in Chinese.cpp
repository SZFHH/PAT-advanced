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
const string num[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
const string m_exp[] = {"Qian" ,"Bai" ,"Shi", ""};
string read4(string s, bool over4) {
	string rv;
	bool isfirst = true;
	int r = 3, L = 0;
	while (r >= 0 && s[r] == '0') --r;
	if (r < 0) return "";
	while (L <= r && s[L] == '0') ++L;
	if (L != 0 && over4) rv = num[0] + " ";
	for (int i = L; i <= r; ++i) {
		if(s[i]!='0') rv += num[s[i] - '0'] + " " + m_exp[i] + " ";
		if (s[i] == '0' && isfirst) {
			rv += num[0] + " ";
			isfirst = false;
		}
	}
	while (*(rv.end() - 1) == ' ') rv.erase(rv.end() - 1);
	return rv;
}
int main()
{
		string s, ans;
		cin >> s;
		if (s[0] == '-') {
			ans += "Fu ";
			s = s.substr(1, s.size() - 1);
		}
		if (s.size() > 8) {
			s = string(3, '0') + s;
			if (read4(s.substr(0, 4), false) != "") ans += read4(s.substr(0, 4), false) + " Yi ";
			if (read4(s.substr(4, 4), true) != "") ans += read4(s.substr(4, 4), true) + " Wan ";
			ans += read4(s.substr(8, 4), true);
		}
		else if (s.size() > 4) {
			s = string(8 - s.size(), '0') + s;
			if (read4(s.substr(0, 4), false) != "") ans += read4(s.substr(0, 4), false) + " Wan ";
			ans += read4(s.substr(4, 4), true);
		}
		else {
			s = string(4 - s.size(), '0') + s;
			ans += read4(s.substr(0, 4), false);
		}
		if (!ans.size()) ans += num[0];
		while (*(ans.end() - 1) == ' ') ans.erase(ans.end() - 1);
		cout << ans;
	return 0;
}