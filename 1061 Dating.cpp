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
const char* week[] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	char d, h;
	int m;
	int i = 0;
	for (; i < s1.size(); ++i) {
		if (s1[i] == s2[i] && s1[i] >= 'A'&&s1[i] <= 'G'&&s2[i] >= 'A'&&s2[i] <= 'G') {
			d = s1[i];
			++i;
			break;
		}
	}
	for (; i < s1.size(); ++i) {
		if (s1[i] == s2[i] && (s1[i] >= 'A'&&s1[i] <= 'N'||isdigit(s1[i]))&&(s2[i] >= 'A'&&s2[i] <= 'N'||isdigit(s2[i]))) {
			h = s1[i];
			++i;
			break;
		}
	}
	for (int i = 0; i < s3.size(); ++i) {
		if (isalpha(s3[i]) && isalpha(s4[i]) && s3[i] == s4[i]) {
			m = i;
			break;
		}
	}
	int int_h = isdigit(h) ? h - '0' : h - 'A' + 10;
	printf("%s %02d:%02d", week[d - 'A'], int_h, m);
	return 0;
}