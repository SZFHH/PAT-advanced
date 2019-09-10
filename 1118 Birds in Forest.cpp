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
int con[10005];

int findroot(int n) {
	while (con[n] >= 0) n = con[n];
	return n;
}

void merge(int n1, int n2) {
	int rt1 = findroot(n1), rt2 = findroot(n2);
	if (rt1 == rt2) return;
	if (con[rt1] < con[rt2]) {
		con[rt1] += con[rt2];
		con[rt2] = rt1;
	}
	else {
		con[rt2] += con[rt1];
		con[rt1] = rt2;
	}
}
int n,m=0;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < 10005; ++i) con[i] = -1;
	int k, c1, c2;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		if (k > 0) {
			scanf("%d", &c1);
            m = max(m,c1);
			for (int i = 0; i < k - 1; ++i) {
				scanf("%d", &c2);
                m = max(m,c2);
				merge(c1, c2);
			}
		}
	}
	int ct = 0;
	for (int i = 1; i <= m; ++i) {
		if (con[i] < 0) ct++;
	}
	printf("%d %d\n", ct, m);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &c1, &c2);
		if (findroot(c1) == findroot(c2)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}