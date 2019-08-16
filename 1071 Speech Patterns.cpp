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
map<string, int> ans;
string tolo(string s) {
	for (auto &c : s) c = tolower(c);
	return s;
}
int main()
{
	string s;
	getline(cin, s, '\n');
	unsigned int i(0), j(0);
	while (i < s.size() && !isalnum(s[i])) i++;
	j = i;
	while (j < s.size()) {
		if (isalnum(s[j])) j++;
		else {
			if(isalnum(s[i])) ans[tolo(s.substr(i, j - i))]++;
			i = j + 1;
			j = i;
		}
	}
	if (i<s.size() && s[j-1]) ans[tolo(s.substr(i, j - i))]++;
	auto maxit = ans.begin();
	int maxc = 0;
	for (auto it = ans.begin(); it != ans.end(); ++it) {
		if (it->second > maxc) {
			maxc = it->second;
			maxit = it;
		}
	}
	cout << maxit->first << ' ' << maxc;
	return 0;
}