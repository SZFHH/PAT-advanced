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

multiset<int> s;
int nums[100005];
int main()
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		s.insert(nums[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (s.count(nums[i]) == 1) {
			cout << nums[i];
			return 0;
		}
	}
	cout << "None";
	return 0;
}