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

struct m_cmp {
	vector<int> & arr_;
	m_cmp(vector<int> & arr) :arr_(arr) {};
	bool operator()(int a, int b) {
		return arr_[a] > arr_[b];
	}
};

struct m_info {
	int rank;
	char course;
	m_info(int rank_, char course_) :rank(rank_), course(course_) {};
	m_info() :m_info(0, 'A') {};
};
void adjust(vector<int> &rk, const vector<int> & gd) {
	int len = rk.size();
	int rank = 1, i = 0, last = gd[rk[0]];
	vector<int> tmp(rk.size());
	while (i < len) {
		if (gd[rk[i]] < last) {
			rank = i + 1;
			last = gd[rk[i]];
		}
		tmp[rk[i]] = rank;
		i++;
	}
	rk = tmp;
}
const char subj[4] = { 'A','C','M','E' };
int main()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> allrank(4 ,vector<int>(n)), allgrade(4, vector<int>(n));
	vector<int> id(n);
	for (int i = 0; i < n; ++i) {
		cin >> id[i];
		for (int j = 1; j < 4; ++j)
			cin >> allgrade[j][i];
		allgrade[0][i] = (allgrade[1][i] + allgrade[2][i] + allgrade[3][i]) / 3.0 + 0.5;
		for (int j = 0; j < 4; ++j)
			allrank[j][i] = i;
	}
	for (int i = 0; i < 4; ++i) {
		sort(allrank[i].begin(), allrank[i].end(), m_cmp(allgrade[i]));
		adjust(allrank[i], allgrade[i]);
	}
	map<int, m_info> mp;
	
	for (int i = 0; i < n; ++i) {
		int minrk = n + 1;
		int minj = 3;
		for (int j = 3; j >= 0; --j) {
			if (allrank[j][i] <= minrk) {
				minrk = allrank[j][i];
				minj = j;
			}
		}
		mp[id[i]] = m_info(minrk, subj[minj]);
	}
	for (int i = 0; i < k; ++i) {
		int stu;
		cin >> stu;
		map<int, m_info>::iterator it = mp.find(stu);
		if (it != mp.end()) 
			cout << it->second.rank << ' ' << it->second.course << endl;
		else
			cout << "N/A" << endl;
	}
	return 0;
}