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
#include<set>
#include<limits.h>
#include<queue>
using namespace std;

struct stime {
	int h, m, s;
	bool operator<(stime t) {
		if (h != t.h)
			return h < t.h;
		else {
			if (m != t.m)
				return m < t.m;
			else
				return s < t.s;
		}
	}
	stime(int hour, int minute, int second) :h(hour), m(minute), s(second) {};
	stime() :stime(0, 0, 0) {};
};
istream& operator >> (istream &in, struct stime & st) {
	in >> st.h;
	in.get();
	in >> st.m;
	in.get();
	in >> st.s;
	return in;
}
struct info {
	string name;
	struct stime in;
	struct stime out;
	info(const string & name_, const struct stime & in_, const struct stime & out_) :name(name_), in(in_), out(out_) {};
};
vector<info> rv;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name;
		struct stime in, out;
		cin >> name;
		cin >> in >> out;
		rv.push_back(info(name, in, out));
	}
	struct stime latest(0, 0, 0);
	struct stime earlist(23, 59, 59);
	int earlisti, latesti;
	for (int i = 0; i < rv.size(); ++i) {
		if (rv[i].in < earlist) {
			earlist = rv[i].in;
			earlisti = i;
		}
		if (!(rv[i].out < latest)) {
			latest = rv[i].out;
			latesti = i;
		}
	}

	cout << rv[earlisti].name << ' ' << rv[latesti].name;
	return 0;
}
