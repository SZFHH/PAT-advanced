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

long int t, at, pat;
int main()
{
	string s;
	cin >> s;
	for (auto it = s.rbegin(); it != s.rend(); ++it) {
		if (*it == 'T') t++;
		else if (*it == 'A') at += t;
		else pat += at;
	}
	cout << pat % 1000000007;
	return 0;
}