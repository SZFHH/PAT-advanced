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
int s, m;
bool isprime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	int k = sqrt(n);
	for (int i = 2; i <= k; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int findnextprime(int n) {
	while (!isprime(n)) ++n;
	return n;
}
int m_hash(int key, int T) {
	return key%T;
}
int h[10010];
int ans[10010];
int findpos(int key) {
	int init = m_hash(key, s), colnum = 0, addamount = 0, pos(init), s2 = s*s;
	while (h[pos]) {
		addamount += (++colnum << 1) - 1;
		pos = init + addamount;
		if (addamount >= s2) return -1;
		if (pos > s - 1) pos %= s;
	}
	h[pos] = key;
	return pos;
}

int main()
{
	cin >> s >> m;
	s = findnextprime(s);
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		ans[i] = findpos(num);
	}
	for (int i = 0; i < m; ++i) {
		if (i != 0) cout << ' ';
		if (ans[i] == -1) cout << '-';
		else cout << ans[i];
	}
	return 0;
}
