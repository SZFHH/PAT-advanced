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
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i) {
		vector<int> v(n);
		stack<int> sk;
		for (int j = 0; j < n; ++j) cin >> v[j];
		int j = 0, s = 0, res = n;
		while (res > 0) {
			if(sk.empty() && s<n) sk.push(++s);
			if (v[j] != sk.top()) {
				if (sk.size() == m || s==n) break;
				else sk.push(++s);
			} 
			else {
				sk.pop();
				j++;
				res--;
			}
		}
		if (res) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}