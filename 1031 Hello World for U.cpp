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
	string s;
	cin >> s;
	int n1, n2;
	n1 = (s.size() + 2) / 3;
	n2 = n1 + (s.size() + 2) % 3;
	for (int i = 0; i < n1 - 1; ++i){
		cout << s[i];
		for (int j = 1; j < n2-1; ++j) cout << ' ';
		cout << s[s.size() - 1 - i] << endl;
	}
	for (int j = n1 - 1; j < s.size() - n1 + 1; ++j)
		cout << s[j];
	return 0;
}