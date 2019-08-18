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
int n, m, k;
struct stu {
	int ttgd, egd, id;
	int schs[8];
	bool operator<(stu s) {
		if (ttgd != s.ttgd) return ttgd > s.ttgd;
		else return egd > s.egd;
	}
	bool operator==(stu s) {
		return (ttgd == s.ttgd) && (egd == s.egd);
	}
};
vector<vector<int>> schools;
vector<stu> stus;
int quoto[105];
bool cpm(int a, int b) {
	return stus[a].id < stus[b].id;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	stus.resize(n);
	schools.resize(m);
	for (int i = 0; i < m; ++i) scanf("%d", &quoto[i]);
	int gde, gdi;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &gde, &gdi);
		for (int j = 0; j < k; ++j) scanf("%d", &stus[i].schs[j]);
		stus[i].ttgd = gde + gdi;
		stus[i].egd = gde;
		stus[i].id = i;
	}
	sort(stus.begin(), stus.end());
	for (int i = 0; i < stus.size();++i) {
		for (int j = 0; j < k; ++j) {
			int sch_id = stus[i].schs[j];
			if (schools[sch_id].size() < quoto[sch_id] || (stus[i] == stus[*(schools[sch_id].end() - 1)])) {
				schools[sch_id].push_back(i);
				break;
			}
		}
	}
	for (auto &s : schools) {
		sort(s.begin(), s.end(), cpm);
		for (int i = 0; i < s.size(); ++i) {
			if (i != 0) printf(" ");
			printf("%d", stus[s[i]].id);
		}
		putchar('\n');
	}
	return 0;
}