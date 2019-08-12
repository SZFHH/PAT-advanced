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

string dbstr(const string & str) {
	int last = 0;
	string rv;
	for (auto it = str.rbegin(); it != str.rend(); ++it) {
		int tmp;
		tmp = (*it - '0') * 2 + last;
		last = tmp / 10;
		rv.push_back(tmp % 10 + '0');
	}
	if (last)
		rv.push_back('1');
	reverse(rv.begin(), rv.end());
	return rv;
}
bool issame(string &str1, string &str2) {
	if (str1.size() != str2.size())
		return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	for (int i = 0; i < str1.size(); ++i)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}
int main()
{
	string s, s2, s3;
	cin >> s;
	s2 = dbstr(s);
	s3 = s2;
	if (issame(s, s2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << s3;
	return 0;
}