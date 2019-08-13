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
struct info {
	string name, id;
	int gd;
};
int main()
{
	info m = info{ "Absent","Absent",101 };
	info f = info{ "Absent","Absent",-1 };
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name, id;
		char g;
		int gd;
		cin >> name >> g >> id >> gd;
		if (g == 'M') {
			if (gd < m.gd) m = info{ name,id,gd };
		}
		else {
			if (gd > f.gd) f = info{ name,id,gd };
		}
	}
	if (f.name != "Absent") cout << f.name << ' ' << f.id << endl;
	else cout << f.name << endl;
	if (m.name != "Absent") cout << m.name << ' ' << m.id << endl;
	else cout << m.name << endl;
	if (f.name != "Absent" && m.name != "Absent") cout << f.gd - m.gd;
	else cout << "NA";
	return 0;
}