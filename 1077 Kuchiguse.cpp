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
string v[105];
bool cpm(string &s1, string &s2) {
	return s1.size() < s2.size();
}
int main()
{
	int n, ct = 0;
	char c;
	cin >> n;
	cin.get();
	sort(v, v + n, cpm);
	for (int i = 0; i < n; ++i) getline(cin, v[i], '\n');
	while (1) {
		int i = 1;
		if (v[0].size() < 1 + ct) break;
		else c = v[0][v[0].size() - 1 - ct];
		for (i = 1; i < n; ++i) {
			if (v[i][v[i].size() - 1 - ct] != c) break;
		}
		if (i != n) break;
		else ct++;
	}
	if (ct) cout << v[0].substr(v[0].size() - ct, ct);
	else cout << "nai";

	return 0;
}
