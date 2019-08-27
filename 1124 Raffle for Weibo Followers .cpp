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
vector<string> users;
set<string> winpool;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	users.resize(n);
	for (int i = 0; i < n; ++i) cin >> users[i];
	if (k > n) {
		cout << "Keep going..." << endl;
		return 0;
	}
	for (int s = k - 1;  s < n; s += m) {
		while (s<n && winpool.find(users[s]) != winpool.end()) s++;
		if (s == n) break;
		cout << users[s] << endl;
		winpool.insert(users[s]);
	}
	return 0;
}