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
string s;
int k;
bool isr(char c, int start) {
	if (start > s.size() - k) return false;
	for (int i = start; i < start + k; ++i) {
		if (s[i] != c) return false;
	}
	return true;
}
int isstuck[130];
set<char> ans;
int main()
{	
	cin >> k >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (isr(s[i], i)) {
			isstuck[s[i]] = 1;
			i += k - 1;
		}
		else isstuck[s[i]] = 0;
	}
	for (int i = 0; i < s.size(); ++i) {
		if (isstuck[s[i]]) ans.insert(s[i]);
	}
	for (int i = 0; i < s.size(); ++i) {
		if (isstuck[s[i]]) {
			cout << s[i];
			isstuck[s[i]] = 0;
		}
	}
	cout << endl;
	for (int i = 0; i < s.size(); ++i) {
		cout << s[i];
		if (ans.find(s[i]) != ans.end()) i += k - 1;
	}
	return 0;
}