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
double stock[1005];
double price[1005];
int rank_m[1005];
int n, d;
bool greater_m(int i, int j) {
	return price[i] / stock[i] > price[j] / stock[j];
}
int main()
{
	cin >> n >> d;
	for (int i = 0; i < n; ++i) cin >> stock[i];
	for (int i = 0; i < n; ++i) cin >> price[i];
	for (int i = 0; i < n; ++i) rank_m[i] = i;
	sort(rank_m, rank_m + n, greater_m);
	double res = d, total(0);
	int j = 0;
	while (res > 0 && j < n) {
		int i = rank_m[j];
		if (stock[i] <= res) {
			res -= stock[i];
			total += price[i];
			j++;
		}
		else {
			total += price[i] / stock[i] * res;
			break;
		}
	}
	printf("%.2f", total);
	return 0;
}