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

string op(const string & str) {
	string restr;
	restr.resize(str.size());
	reverse_copy(str.begin(), str.end(), restr.begin());
	int last = 0;
	string rv;
	for (int i = 0; i < str.size(); ++i) {
		int tmp;
		tmp = str[i] - '0' + restr[i] - '0' + last;
		last = tmp / 10;
		rv.push_back(tmp % 10 + '0');
	}
	if (last)
		rv.push_back('1');
	reverse(rv.begin(), rv.end());
	return rv;
}
bool palin(string &str) {
	int len = str.size() / 2;
	for (int i = 0; i < len; ++i) {
		if (str[i] != str[str.size() - 1 - i])
			return false;
	}
	return true;

}
int main()
{
	string s;
	int k;
	cin >> s >> k;
	int i = 0;
	while (i < k && !palin(s)) {
		s = op(s);
		i++;
	}
	cout << s << endl;
	cout << i;
	return 0;
}