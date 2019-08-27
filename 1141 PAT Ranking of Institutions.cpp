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
struct sch {
	string name;
	double tws;
	int ns;
	bool operator<(sch &s) {
		if (int(tws) != int(s.tws)) return int(tws) > int(s.tws);
		else {
			if (ns != s.ns) return ns < s.ns;
			else return name < s.name;
		}
	}
};
map<string, sch> mp;
vector<sch> ans;
int main()
{
	int n;
	scanf("%d", &n);
	string name, sh;
	int gd;
	for (int i = 0; i < n; ++i) {
		cin >> name;
		scanf("%d", &gd);
		cin >> sh;
		transform(sh.begin(), sh.end(), sh.begin(), ::tolower);
		mp[sh].ns++;
		mp[sh].name = sh;
		if (name[0] == 'B') mp[sh].tws += gd / 1.5;
		else if (name[0] == 'A') mp[sh].tws += gd;
		else mp[sh].tws += gd*1.5;
	}
	for (auto &e : mp) ans.push_back(e.second);
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	int last = INT_MAX, rank = 1;
	for (int i = 0; i < ans.size(); ++i) {
		if (int(ans[i].tws) < last) {
			rank = i + 1;
			last = ans[i].tws;
		}
		printf("%d %s %d %d\n", rank, ans[i].name.c_str(), int(ans[i].tws), ans[i].ns);
	}
	return 0;
}