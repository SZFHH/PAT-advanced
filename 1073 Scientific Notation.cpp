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

int main()
{
	int syb, exp, index, dotpos;
	string s, lo, ans;
	cin >> s;
	syb = s[0] == '-' ? -1 : 1;
	index = s.find('E');
	lo = s[1] + s.substr(3, index - 3);
	exp = atoi(s.substr(index + 1, s.size() - index - 1).c_str());
	dotpos = exp + 1;
	if (dotpos <= 0) ans = "0." + string(-dotpos, '0') + lo;
	else {
		if (lo.size() == dotpos) ans = lo;
		else if (lo.size() < dotpos) ans = lo + string(dotpos - lo.size(), '0');
		else ans = lo.substr(0, dotpos) + "." + lo.substr(dotpos, lo.size() - dotpos);
	}
	if (syb == -1) ans = '-' + ans;
	cout << ans;
	return 0;
}