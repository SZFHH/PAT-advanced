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
string int2s(int n) {
	string rv;
	for (int k = 1000; k >= 1; k/=10) {
		rv.push_back(n / k + '0');
		n %= k;
	}
	return rv;
}
int main()
{
	string s1, s2;
	cin >> s1;
	s1 = string(4 - s1.size(), '0') + s1;
	int ans = -1;
	while (ans != 6174 && ans!=0) {
		sort(s1.begin(), s1.end(), greater<char>());
		s2.resize(s1.size());
		reverse_copy(s1.begin(), s1.end(), s2.begin());
		ans = atoi(s1.c_str()) - atoi(s2.c_str());
		printf("%04d - %04d = %04d\n", atoi(s1.c_str()), atoi(s2.c_str()), ans);
		s1 = int2s(ans);
	}
	return 0;
}

