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
const int closetime = 13 * 3600 - 1;
struct m_time {
	int h, m, s;
	int tt;
	void caltt() {
		tt = (h-8) * 3600 + m * 60 + s;
	}
	m_time(int tts) {
		h = tts / 3600 + 8;
		tts %= 3600;
		m = tts / 60;
		tts %= 60;
		s = tts;
	}
	m_time() :m_time(0) {};
	bool operator<(m_time t){return tt < t.tt;}
};
istream & operator >> (istream& in, m_time & t) {
	scanf("%d:%d:%d", &t.h, &t.m, &t.s);
	t.caltt();
	return in;
}
ostream & operator<<(ostream & o, const m_time & t) {
	printf("%02d:%02d:%02d", t.h, t.m, t.s);
	return o;
}
struct info {
	m_time arv;
	int endu, isvip;
	bool operator<(info i) {return arv < i.arv;}
};
vector<info> players;
vector<int> vips;
int lastfns[105];
int nums[105];
int n, m, k;
int choostb(int t, int isvip) {
	if (isvip){
		for (auto &v : vips) 
			if (lastfns[v] <= t) return v;
	}
	int mint = INT_MAX, mini = 1;
	for (int i = 1; i <= m; ++i) {
		if (lastfns[i] <= t) return i;
		if (mint > lastfns[i]) {
			mint = lastfns[i];
			mini = i;
		}
	}
	return mini;
}
int isviptb(int tb) {
	for (auto &b : vips) {
		if (b == tb) return true;
	}
	return false;
}
int nextvip(int fns, int curi) {
	for (int i = curi; i < n&&players[i].arv.tt <= fns; ++i) {
		if (players[i].isvip && players[i].endu) return i;
	}
	return curi;
}
int main()
{
	cin >> n;
	players.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> players[i].arv >> players[i].endu >> players[i].isvip;
		if (players[i].endu > 120) players[i].endu = 120;
		players[i].endu *= 60;
	}
	cin >> m >> k;
	vips.resize(k);
	for (int i = 0; i < k; ++i)
		cin >> vips[i];
	sort(vips.begin(), vips.end());
	sort(players.begin(), players.end());
	for (int i = 0; i < players.size();++i) {
		int p = i;
		int wait, turntime;
		if (players[p].endu) {
			int tb = choostb(players[p].arv.tt, players[p].isvip);
			if (isviptb(tb)) {
				p = nextvip(lastfns[tb],p);
				if (p != i) i--;
			}
			turntime = players[p].arv.tt >= lastfns[tb] ? players[p].arv.tt : lastfns[tb];
			lastfns[tb] = turntime + players[p].endu;
			wait = (turntime - players[p].arv.tt) / 60.0 + 0.5;
			if (turntime > closetime) break;
			cout << players[p].arv << ' ' << m_time(turntime) << ' ' << wait << endl;
			players[p].endu = 0;
			nums[tb] ++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (i != 1) cout << ' ';
		cout << nums[i];
	}
	return 0;
}