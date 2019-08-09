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

const char rst[3] = { 'W','T','L' };
int main()
{
	double tt = 1;
	for (int i = 0; i < 3; ++i) {
		double maxodd(0);
		int maxi = 0;
		for (int j = 0; j < 3; ++j)
		{
			double tmp;
			cin >> tmp;
			if (tmp > maxodd) {
				maxodd = tmp;
				maxi = j;
			}
		}
		tt *= maxodd;
		cout << rst[maxi] << ' ';
	}
	cout << fixed << setprecision(2);
	cout << (tt*0.65 - 1) * 2;
	return 0;
}
