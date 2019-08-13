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
int np[1005][1005];
int main()
{
	string s;
	getline(cin, s, '\n');
	int ans = 1;
	for (int i = 0; i < s.size(); ++i)
		np[i][i] = 1;
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == s[i + 1]) {
			ans = 2;
			np[i][i + 1] = 1;
		}
	}
	for (int n = s.size() - 2; n > 0; --n) {
		int i = 0, j = s.size() - n;
		for (int k = 0; k < n; ++k) {
			if (np[i + 1][j - 1] && s[i] == s[j]) {
				np[i][j] = 1;
				ans = max(ans, j - i + 1);
			}
			i++, j++;
		}
	}
	cout << ans;
	return 0;
}