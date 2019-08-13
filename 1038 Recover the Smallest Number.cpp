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
bool cpm(const string & s1, const string &s2) {
	if (s1.size() == s2.size())
		return s1 < s2;
	else if (s1.size() < s2.size()) {
		if (s2.find(s1) != 0) return s1 < s2;
		else return s1 + s2.substr(s1.size(), s2.size() - s1.size()) < s2.substr(s1.size(), s2.size() - s1.size()) + s1;
	}
	else {
		if (s1.find(s2) != 0) return s1 < s2;
		else return s2 + s1.substr(s2.size(), s1.size() - s2.size()) > s1.substr(s2.size(), s1.size() - s2.size()) + s2;
	}
}
bool allzero(string &s) {
	for (auto c : s) {
		if (c != '0') return false;
	}
	return true;
}
int main()
{
	int n;
	vector<string> allnum;
	string ans;
	cin >> n;
	allnum.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> allnum[i];
	sort(allnum.begin(), allnum.end(), cpm);
	for (auto &num:allnum) ans += num;
	if (allzero(ans))
		cout << 0;
	else{
		int i = 0;
		while (ans[i] == '0') i++;
		for (; i < ans.size(); ++i) cout << ans[i];
	}
	return 0;
}