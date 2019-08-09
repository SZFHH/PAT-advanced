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
int N, M, K, Q;
vector<queue<int>> allws;

int lastfns[25];
int ppfinish[1005];
int ppendure[1005];
bool allfull() {
	for (auto &q : allws) {
		if (q.size() < M)
			return false;
	}
	return true;
}

int chooseline() {
	int qsize = M + 5, q = 0;
	for (int i = 0; i < N; ++i) {
		if (allws[i].size() < qsize) {
			qsize = allws[i].size();
			q = i;
		}
	}
	return q;
}

void popone() {
	int minfirst = INT_MAX;
	for (auto &q : allws) {
		minfirst = min(minfirst, ppendure[q.front()]);
	}
	for (auto &q : allws) {
		if (ppendure[q.front()] == minfirst)
			q.pop();
		else
			ppendure[q.front()] -= minfirst;
	}
}
void prt(int mi) {
	if (mi == -1)
	{
		printf("Sorry\n");
		return;
	}
	int h = mi / 60 + 8;
	mi = mi % 60;
	//cout.fill('0');
	printf("%02d:%02d\n", h, mi);
}
int main()
{
	cin >> N >> M >> K >> Q;
	allws = vector<queue<int>>(N);
	for (int i = 1; i <= K; ++i) {
		cin >> ppendure[i];
		if (allfull()) 
			popone();
		int q = chooseline();
		allws[q].push(i);
		lastfns[q] += ppendure[i];
		ppfinish[i] = lastfns[q];
		if (ppfinish[i] - ppendure[i] > 539)
			ppfinish[i] = -1;
	}
	for (int i = 0; i < Q; ++i) {
		int query;
		cin >> query;
		prt(ppfinish[query]);
	}
	return 0;
}