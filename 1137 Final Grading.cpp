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
	int gp, gm, gf, g;
	bool operator<(stu &s) {
		return g == s.g ? name<s.name : g>s.g;
	}
	void cal() {
		if (gm == -1 && gf == -1) g = 0;
		else if (gm == -1) g = gf;
		else if (gf == -1) g = gm*0.4 + 0.5;
		else {
			if (gm > gf) g = gm*0.4 + gf*0.6 + 0.5;
			else g = gf;
		}
	}
};
map<string, stu> mp;
vector<stu> v;
int n, m, k;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	string name;
	int gd;
	for (int i = 0; i < n; ++i) {
		cin >> name;
		scanf("%d", &gd);
		if (gd >= 200) mp[name] = stu{ name,gd,-1,-1,0 };
	}
	for (int i = 0; i < m; ++i) {
		cin >> name;
		scanf("%d", &gd);
		if (mp.find(name) != mp.end()) mp[name].gm = gd;
	}
	for (int i = 0; i < k; ++i) {
		cin >> name;
		scanf("%d", &gd);
		if (mp.find(name) != mp.end()) mp[name].gf = gd;
	}
	for (auto &s : mp) {
		s.second.cal();
		if(s.second.g>=60) v.push_back(s.second);
	}
	sort(v.begin(), v.end());
	for (auto &s : v) {
		printf("%s %d %d %d %d\n", s.name.c_str(), s.gp, s.gm, s.gf, s.g);
	}
	return 0;
}