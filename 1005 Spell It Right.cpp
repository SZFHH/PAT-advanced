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

int cal(const string & s) {
	int sum = 0;
	for (auto &i : s)
		sum += i - '0';
	return sum;
}
const char* engnum[] = { "zero", "one","two","three","four","five","six","seven","eight","nine" };
int main()
{
	string input, output;
	cin >> input;
	int rv = cal(input);
	int k = 1000;
	while (k >= 1) {
		output.push_back(rv / k + '0');
		rv %= k;
		k /= 10;
	}
	if (atoi(output.c_str()) == 0)
		cout << engnum[0];
	else
	{
		bool isfirst = true;
		int i = 0;
		while (output[i] == '0')
			++i;
		for (; i < output.size(); ++i)
		{
			if (isfirst) {
				cout << engnum[output[i] - '0'];
				isfirst = false;
			}
			else
				cout << ' ' << engnum[output[i] - '0'];
		}
	}

	return 0;
}
