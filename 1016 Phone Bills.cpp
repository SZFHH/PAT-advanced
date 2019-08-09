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
int month;
int toll[24];
int tollperday;
int min2hour(int n) {
	return n % 1440 / 60;
}
struct m_time {
	int d, h, m;
	int tt;
	m_time() :m_time(0, 0, 0) {};
	m_time(int day, int hour, int minute) :d(day), h(hour), m(minute) {
		caltt();
	}
	int operator-(m_time time_) {
		return tt - time_.tt;
	}
	bool operator<(m_time time_) {
		return tt < time_.tt;
	}
	void caltt() {
		tt = (d - 1) * 24 * 60 + h * 60 + m;
	}
};
istream & operator >> (istream& in, m_time &t) {
	scanf("%d:%d:%d:%d", &month, &t.d, &t.h, &t.m);
	t.caltt();
	return in;
}
ostream & operator<<(ostream &o, const m_time &t) {
	o.fill('0');
	o << setw(2) << t.d << ':' << setw(2) << t.h << ':' << setw(2) << t.m;
	return o;
}
struct info {
	string name;
	m_time time_;
	char status;
	info(string n, m_time t, char st) :name(n), time_(t),status(st) {};
	bool operator<(info info2) {
		if (name != info2.name)
			return name < info2.name;
		else
			return time_ < info2.time_;
	}
};
int cal(m_time ontime, m_time offtime) {
	int sum = 0;
	int tt1 = ontime.tt, tt2 = offtime.tt;
	if (tt2 - tt1 >= 1440)
	{
		sum += (tt2 - tt1) / 1440 * tollperday;
		tt1 += (tt2 - tt1)/1440 * 1440;
	}
	for (int t = tt1; t < tt2; ++t)
		sum += toll[min2hour(t)];
	return sum;
}
void nextit(vector<info>::iterator & it, vector<info> &arr) {
	while (it != arr.end() && it->name == "None")
		it++;
}
vector<info> allrecord;
multimap<string, pair<m_time, m_time>> mp;
typedef multimap<string, pair<m_time, m_time>>::iterator userit;
set<string> allpp;
int main()
{
	for (int i = 0; i < 24; ++i)
		cin >> toll[i];
	tollperday = accumulate(toll, toll + 24, 0) * 60;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name, stat;
		m_time tm;
		cin >> name >> tm >> stat;
		allrecord.push_back(info(name, tm,stat[1]));
		
	}
	sort(allrecord.begin(), allrecord.end());
	int len = allrecord.size();
	for (int i = 0; i < len;) {
		while (i < len && allrecord[i].status == 'f')
			++i;
		if (i == len)
			break;
		if (i < len - 1 && allrecord[i + 1].name == allrecord[i].name && allrecord[i + 1].status == 'f')
		{
			mp.insert(make_pair(allrecord[i].name, make_pair(allrecord[i].time_, allrecord[i + 1].time_)));
			allpp.insert(allrecord[i].name);
			i += 2;
		}
		else
			i++;
	}
	cout.fill('0');
	cout << fixed << setprecision(2);
	for (auto &user : allpp) {
		double sum = 0;
		cout << user << ' ' << setw(2) << month << endl;
		pair<userit, userit> range = mp.equal_range(user);
		for (auto it = range.first; it != range.second; ++it) {
			double tt = cal(it->second.first, it->second.second) / 100.0;
			int endu = it->second.second - it->second.first;
			cout << it->second.first << ' ' << it->second.second << ' ' << endu << " $" << tt << endl;
			sum += tt;
		}
		cout << "Total amount: $" << sum << endl;
	}
	return 0;
}