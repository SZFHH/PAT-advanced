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
#include<set>
#include<limits.h>
#include<queue>
using namespace std;
int arr[10005];

int main()
{
	int last = 0;
	int n;
	cin >> n;
	int total = 0;
	for (int i = 0; i < n; ++i) {
		int fl;
		cin >> fl;
		if (last < fl)
			total += (fl - last) * 6;
		else
			total += (last - fl) * 4;
		last = fl;
	}
	total += n * 5;
	cout << total;

	return 0;
}
