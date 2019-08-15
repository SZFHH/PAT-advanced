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
	long long int a, b, c, d, e, f;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
	d = (a + d) * 17 * 29 + (b + e) * 29 + f + c;
	a = d / (17 * 29); d %= (17 * 29);
	b = d / 29; d %= 29;
	c = d;
	printf("%lld.%lld.%lld", a, b, c);
	return 0;
}