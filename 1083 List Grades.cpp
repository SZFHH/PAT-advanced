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
struct stu {
	string name, id;
	int grade;
	bool operator<(const stu &s) {
		return grade > s.grade;
	}
};
vector<stu> v;
int main()
{

	int n, gd1, gd2, ct(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) cin >> v[i].name >> v[i].id >> v[i].grade;
	cin >> gd1 >> gd2;
	sort(v.begin(), v.end());
	for (auto &s : v) {
		if (s.grade >= gd1 && s.grade <= gd2) {
			cout << s.name << ' ' << s.id << endl;
			ct++;
		}
	}
	if (!ct) cout << "NONE";
	return 0;
}