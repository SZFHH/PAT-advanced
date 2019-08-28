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
int h[10010];
int msize, n, m, up;
bool isprime(int n) {
	if (n == 2) return true;
	if (n == 1) return false;
	int k = sqrt(n);
	for (int i = 2; i <= k; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int getprime(int n) {
	while (!isprime(n)) ++n;
	return n;
}
bool insert(int key) {
	int pos = key%msize, c = 0, inc = 0, init = pos;
	while (h[pos]) {
		inc += (c++ << 1) + 1;
		if (inc >= up) return false;
		pos = (init + inc) % msize;
	}
	h[pos] = key;
	return true;
}
int find(int key) {
	int pos = key%msize, c = 0, inc = 0, ct = 0, init = pos;
	while (h[pos] && h[pos]!=key) {
		inc += (c++ << 1) + 1;
		if (inc > up) break;
		pos = (init + inc) % msize;
		++ct;
	}
	return ct + 1;
}
int main()
{
	int c;
	double sum = 0;
	scanf("%d%d%d", &msize, &n, &m);
	msize = getprime(msize);
	up = msize*msize;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c);
		if (!insert(c)) printf("%d cannot be inserted.\n", c);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &c);
		sum += find(c);
	}
	printf("%.1lf", sum / m);
	return 0;
}