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

int main()
{
	vector<int> result(100005);
	int data[100005];
	int next[100005];
	int firstadd, n, k;
	cin >> firstadd >> n >> k;
	for (int i = 0; i < n; ++i) {
		int add;
		scanf("%d", &add);
		scanf("%d%d", &data[add], &next[add]);
	}
	int i = 0;
	while (firstadd != -1) {
		result[i++] = firstadd;
		firstadd = next[firstadd];
	}
	result[i] = -1;
	for (int j = 0; j <= i - k; j += k) reverse(result.begin() + j, result.begin() + j + k);
	for (int j = 0; j < i - 1; ++j) printf("%05d %d %05d\n", result[j], data[result[j]], result[j + 1]);
	printf("%05d %d %d\n", result[i - 1], data[result[i - 1]], -1);
	return 0;
}
