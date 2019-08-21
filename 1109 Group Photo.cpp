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
struct stu {
	string name;
	int h;
	bool operator<(stu & s) {
		return h == s.h ? name<s.name : h>s.h;
	}
};
vector<stu> s;
vector<vector<int>> ans;
int main()
{	
	int n, k, nrofr, nrofa;
	cin >> n >> k;
	s.resize(n);
	nrofa = n / k;
	nrofr = nrofa + n%k;
	ans.push_back(vector<int>(nrofr));
	for (int i = 1; i < k; ++i) ans.push_back(vector<int>(nrofa));
	for (int i = 0; i < n; ++i) cin >> s[i].name >> s[i].h;
	sort(s.begin(), s.end());
	int i = 0;
	for (int j = 0; j < k; ++j) {
		int r = ans[j].size() - 1, mid = (r + 1) / 2, inc = 1;
		ans[j][mid] = i;
		++i;
		while (1) {
			if (mid - inc >= 0) {
				ans[j][mid - inc] = i;
				++i;
			}
			if (mid + inc <=r ) {
				ans[j][mid + inc] = i;
				++i;
			}
			else break;
			inc++;
		}
	}
	for (auto &r : ans) {
		for (int i = 0; i < r.size(); ++i) {
			if (i != 0) cout << ' ';
			cout << s[r[i]].name;
		}
		cout << endl;
	}
	return 0;
}