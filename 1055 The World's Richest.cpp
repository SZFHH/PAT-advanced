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

struct pp {
	string name;
	int age, netw;
	bool operator<(pp &p) {
		if(netw!=p.netw) return netw > p.netw;
		else {
			if (age != p.age) return age < p.age;
			else return name < p.name;
		}
	}
};
vector<pp> ap;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int maxnum, lo, hi, ct;
	ap.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> ap[i].name;
		scanf("%d%d", &ap[i].age, &ap[i].netw);
	}
	sort(ap.begin(), ap.end());
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &maxnum, &lo, &hi);
		ct = 0;
		printf("Case #%d:\n", i);
		for (auto &p : ap) {
			if (ct == maxnum) break;
			if (p.age >= lo && p.age <= hi) {
				printf("%s %d %d\n", p.name.c_str(), p.age, p.netw);
				ct++;
			}
		}
		if (!ct) printf("None\n");
	}
	return 0;
}