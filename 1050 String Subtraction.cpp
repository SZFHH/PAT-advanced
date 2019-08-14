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

set<char> cpool;
int main()
{
	string s1, s2;
	getline(cin, s1, '\n');
	getline(cin, s2, '\n');
	for (auto &c : s2) cpool.insert(c);
	for (auto&c : s1) {
		if (cpool.find(c) != cpool.end()) c = '\n';
	}
	for (auto &c : s1) {
		if (c != '\n') printf("%c", c);
	}
	return 0;
}