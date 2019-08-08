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
bool allneg(int n) {
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] >= 0)
			return false;
	}
	return true;
}
bool allnegzero(int n) {
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int maxsum(0), maxi(0), maxj(0), i(0), j(0), sum(0);
	if (allneg(n))
	{
		cout << 0 << ' ' << arr[0] << ' ' << arr[n - 1] << endl;
		return 0;
	}
	if (allnegzero(n)) {

		cout << 0 << ' ' << 0 << ' ' << 0 << endl;
		return 0;
	}
	while (i < n&&j < n) {
		sum += arr[j];
		if (sum < 0) {
			i = j + 1;
			sum = 0;
			j = i;
			continue;
		}
		else if (sum > maxsum) {
			maxi = i;
			maxj = j;
			maxsum = sum;
		}
		j++;
	}
	cout << maxsum << ' ' << arr[maxi] << ' ' << arr[maxj] << endl;

	return 0;
}
