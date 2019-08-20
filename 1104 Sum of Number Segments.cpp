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

int main()
{
	int n;
	double sum(0), tmp;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &tmp);
		sum += tmp*(i + 1)*(n - i);
	}
	printf("%.2f", sum);
	return 0;
}