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

int ct[130];
int main()
{
	string s, b;
	bool flag = true;
	cin >> s >> b;
	memset(ct, 0, sizeof(ct));
	for (auto &c : b) ct[c]++;
	for (auto &c : s) ct[c]--;
	int sum = 0;
	for (auto &c : b) {
		if (ct[c] > 0) {
			flag = false;
			sum += ct[c];
			ct[c] = 0;
		}
	}
	if (flag) cout << "Yes " << s.size() - b.size();
	else cout << "No " << sum;
	return 0;
}