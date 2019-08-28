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
int ans[100005];

int main()
{
	int n, c;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c);
		if (c > 0 && c <= n) ans[c] = 1;
	}
	int i = 1;
	while (ans[i]) ++i;
	printf("%d", i);
	return 0;
}