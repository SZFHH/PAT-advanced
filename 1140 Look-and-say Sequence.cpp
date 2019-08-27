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
string ct(string &s) {
	string rv;
	char last = s[0];
	int ct = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (last == s[i]) ct++;
		else {
			rv.push_back(last);
			rv.push_back(ct + '0');
			last = s[i];
			ct = 1;
		}
	}
	rv.push_back(last);
	rv.push_back(ct + '0');
	return rv;
}
int main()
{
	string s;
	int n;
	cin >> s >> n;
	while (--n) s = ct(s);
	cout << s;
	return 0;
}