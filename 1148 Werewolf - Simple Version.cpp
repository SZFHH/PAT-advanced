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
bool sg[105], tg[105];
int s[105];
int n;
int main()
{
	int c;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c);
		if (c < 0) sg[i] = false;
		else sg[i] = true;
		s[i] = abs(c);
		tg[i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		tg[i] = 0;
		for (int j = i + 1; j <= n; ++j) {
			tg[j] = 0;
			int ct = 0;
			if ((!sg[i] == tg[s[i]] && sg[j] == tg[s[j]]) || (sg[i] == tg[s[i]] && !sg[j] == tg[s[j]])) {
				for (int k = 1; k <= n; ++k) {
					if (k == i || k == j) continue;
					if (sg[k] != tg[s[k]]) ++ct;
					if (ct == 2) break;
				}
			}
			if (ct == 1) {
				printf("%d %d", i, j);
				return 0;
			}
			tg[j] = 1;
		}
		tg[i] = 1;
	}
	printf("No Solution");
	return 0;
}