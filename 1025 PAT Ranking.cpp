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

struct testee {
	string id;
	int grade;
	int localrk;
	int localeid;
	bool operator<(testee t) {
		if (grade == t.grade)
			return id < t.id;
		else
			return grade > t.grade;
	}
};
vector<vector<testee>> alltestee;
int main()
{
	int n;
	cin >> n;
	alltestee.resize(n);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		alltestee[i].resize(num);
		for (int j = 0; j < num; ++j) {
			cin >> alltestee[i][j].id >> alltestee[i][j].grade;
			alltestee[i][j].localeid = i+1;
		}
	}
	vector<testee> mg;
	for (auto &v : alltestee) {
		sort(v.begin(), v.end());
		int lastgd = v[0].grade, i = 1, currk=1;
		for (auto &t : v) {
			if (t.grade != lastgd)
			{
				currk = i;
				lastgd = t.grade;
			}
			t.localrk = currk;
			i++;
			mg.push_back(t);
		}
	}
	sort(mg.begin(), mg.end());
	cout << mg.size() << endl;
	int lastgd = mg[0].grade, i = 1, currk = 1;
	for (auto & t : mg) {
		if (t.grade != lastgd)
		{
			currk = i;
			lastgd = t.grade;
		}
		i++;
		cout << t.id << ' ' << currk << ' ' << t.localeid << ' ' << t.localrk << endl;
	}
	return 0;
}