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
using namespace std;
int rv[130];


int main()
{

	int add1, add2;
	cin >> add1 >> add2;
	int add = add1 + add2;
	int a[3];
	int k = 1000000;
	bool syb = true;
	if (add < 0) {
		add = -add;
		syb = false;
	}
	for (int i = 0; i < 3; ++i) {
		a[i] = add / k;
		add = add%k;
		k /= 1000;
	}
	int i = 0;
	while (i<3 && a[i] == 0)
		i++;
	cout.fill('0');
	if (!syb)
		cout << '-';
	if (i == 0)
		cout << a[0] << ',' << setw(3) << a[1] << ',' << setw(3) << a[2];
	else if (i == 1)
		cout << a[1] << ',' << setw(3) << a[2];
	else
		cout << a[2];
	

	return 0;
}
