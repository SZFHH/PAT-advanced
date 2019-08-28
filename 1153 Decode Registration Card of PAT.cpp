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
struct sinfo {
	int id, tt;
	bool operator<(sinfo &s) {
		return tt == s.tt ? id<s.id : tt>s.tt;
	}
};
struct stu {
	char level;
	int stid, date, id, score;
	string ss;
	stu(string & s, int score_) {
		level = s[0];
		stid = atoi(s.substr(1, 3).c_str());
		date = atoi(s.substr(4, 6).c_str());
		id = atoi(s.substr(10, 3).c_str());
		score = score_;
		ss = s;
	}
	bool operator<(stu &s) {
		return score == s.score ? ss<s.ss : score>s.score;
	}
};
vector<stu> v;
int n, m;
int main()
{
	string tmps;
	int sc;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		cin >> tmps;
		scanf("%d", &sc);
		v.push_back(stu(tmps, sc));
	}
	sort(v.begin(), v.end());
	int type;
	string cmd;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &type);
		cin >> cmd;
		printf("Case %d: %d %s\n", i + 1, type, cmd.c_str());
		bool flag = true;
		if (type == 1) {
			char le = cmd[0];
			for (auto &s : v) {
				if (s.level == le) {
					flag = false;
					printf("%s %d\n", s.ss.c_str(), s.score);
				}
			}
		}
		else if (type == 2) {
			int sn = atoi(cmd.c_str()), ttp(0), tts(0);
			for (auto &s : v) {
				if (s.stid == sn) {
					++ttp;
					tts += s.score;
				}
			}
			if (ttp) {
				printf("%d %d\n", ttp, tts);
				flag = false;
			}
		}
		else {
			int da = atoi(cmd.c_str());
			unordered_map<int, int> mp;
			for (auto &s : v) {
				if (s.date == da) mp[s.stid]++;
			}
			vector<sinfo> tmpv;
			for (auto &e : mp) tmpv.push_back(sinfo{ e.first,e.second });
			if (tmpv.size()) flag = false;
			sort(tmpv.begin(), tmpv.end());
			for (auto &e : tmpv) printf("%d %d\n", e.id, e.tt);
		}
		if (flag) printf("NA\n");
	}
	return 0;
}