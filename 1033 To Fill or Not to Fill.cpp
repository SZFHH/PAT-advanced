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

double maxc, d, per, maxd;
int n;
struct station {
	double price, dis;
	bool operator<(station s) {
		return price < s.price;
	}
};
bool cpm(station &s1, station &s2) {
	return s1.dis < s2.dis;
}
vector<station> alls;
vector<int> ans;
int nextstat(double curd) {
	double lowd = curd - maxd;
	for (int i = 0; i < alls.size(); ++i) {
		if (alls[i].dis >= lowd && alls[i].dis < curd)
			return i;
	}
	return -1;
}
void maxlen() {
	sort(alls.begin(), alls.end(), cpm);
	double last = -maxd;
	for (auto & s : alls){
		if (s.dis - last > maxd) {
			printf("The maximum travel distance = %.2f", last + maxd);
			return;
		}
		last = s.dis;
	}
	printf("The maximum travel distance = %.2f", last + maxd);
}
double caladd(int curs) {
	int hid = alls[ans[curs]].dis + maxd;
	for (int i = curs + 1; i < ans.size() && alls[ans[i]].dis <= hid; i++) {
		if (alls[ans[i]].price <= alls[ans[curs]].price)
			return alls[ans[i]].dis - alls[ans[curs]].dis;
	}
	return maxd;
}
int main()
{
	cin >> maxc >> d >> per >> n;
	maxd = maxc*per;
	double tmpp, tmpd;
	for (int i = 0; i < n; ++i) {
		cin >> tmpp >> tmpd;
		alls.push_back(station{ tmpp,tmpd });
	}
	sort(alls.begin(), alls.end());
	double des = d;
	while (abs(des)>1e-7) {
		int sid = nextstat(des);
		if (sid == -1) {
			maxlen();
			return 0;
		}
		ans.push_back(sid);
		des = alls[sid].dis;
	}
	reverse(ans.begin(), ans.end());
	double sum = 0, curc = 0;
	for (int i = 0; i < ans.size(); ++i) {
		if (i != 0)
			curc -= alls[ans[i]].dis - alls[ans[i - 1]].dis;
		double add = caladd(i);
		sum += (add - curc)*alls[ans[i]].price;
		curc = add;
		
	}
	sum += (d - alls[*(ans.end()-1)].dis - maxd)*alls[*(ans.end()-1)].price;
	printf("%.2f", sum / per);
	return 0;
}