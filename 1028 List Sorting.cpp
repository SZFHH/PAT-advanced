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
	int id;
	string name;
	int grade;
};
bool cmp1(stu &s1, stu &s2) {
	return s1.id < s2.id;
}
bool cmp2(stu &s1, stu &s2) {
	if (s1.name != s2.name) 
		return s1.name < s2.name;
	return s1.id < s2.id;
}
bool cmp3(stu &s1, stu &s2) {
	if (s1.grade != s2.grade)
		return s1.grade < s2.grade;
	return s1.id < s2.id;
}
vector<stu> stus;
bool(*cmps[])(stu &, stu &)  = { cmp1,cmp2,cmp3 };
int main()
{
	int n, m;
	cin >> n >> m;
	stus.resize(n);
	for (int i = 0; i < n; ++i) 
		cin >> stus[i].id >> stus[i].name >> stus[i].grade;
	sort(stus.begin(), stus.end(), cmps[m-1]);
	for (auto &s : stus)
		printf("%06d %s %d\n", s.id, s.name.c_str(), s.grade);
	return 0;
}