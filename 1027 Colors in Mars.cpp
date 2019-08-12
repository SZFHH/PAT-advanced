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

const char ss[13] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };
string ten213(int num) {
	string tmp;
	tmp.push_back(ss[num / 13]);
	tmp.push_back(ss[num % 13]);
	return tmp;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	string s1(ten213(a)), s2(ten213(b)), s3(ten213(c));
	cout << '#' << s1 << s2 << s3;
	return 0;
}