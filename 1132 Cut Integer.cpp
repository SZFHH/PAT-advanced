#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
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
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (atoi(s.c_str()) % (atoi(s.substr(0, s.size() / 2).c_str()) * atoi(s.substr(s.size() / 2, s.size() / 2).c_str())))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}