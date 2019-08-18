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
int isw[130];
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int j = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if (s2[j] != s1[i]) isw[s1[i]] = 1;
		else j++;
	}
	for (auto &c : s1) {
		if (isw[c]) {
			if (isalpha(c)) {
				cout << char(toupper(c));
				isw[tolower(c)] = 0;
				isw[toupper(c)] = 0;
			}
			else {
				isw[c] = 0;
				cout << c;
			}
		}
	}
	return 0;
}