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

int cl[100005];
int main()
{
	int n, m, e1, e2, maxe, mine;
	cin >> n;
	for (int i = 2; i <= n+1; ++i) {
		scanf("%d", &cl[i]);
	}
	for (int i = 2; i <= n; ++i) cl[i] += cl[i - 1];
	cl[1] = 0;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &e1, &e2);
		if (e1 > e2) maxe = e1, mine = e2;
		else maxe = e2, mine = e1;
		printf("%d\n", min(cl[maxe] - cl[mine], cl[n]-cl[maxe] + cl[mine] + cl[n+1]));
	}
	return 0;
}