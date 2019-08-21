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
bool isnum(string &s) {
	int i = 0, dots(0), len;
	len = s.size();
	if (s[0] == '-') ++i;
	else if (!isdigit(s[0])) return false;
	if (i >= len || !isdigit(s[i])) return false;
	else ++i;
	for (; i < len; ++i) {
		if (s[i] == '.') ++dots;
		else if (!isdigit(s[i])) return false;
		if (dots == 2) return false;
	}
	return true;
}
bool isok(string &s) {
	if (s.size() < 9 && isnum(s)) {
		double n;
		n = atof(s.c_str());
		int index = s.find('.');
		if (index != -1 && s.size() - index > 3) return false;
		if (n >= -1000 && n <= 1000) return true;
	}
	return false;
}
int main()
{	
	int n, ct(0);
	scanf("%d", &n);
	double sum(0);
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (isok(s)) {
			sum += atof(s.c_str());
			++ct;
		}
		else printf("ERROR: %s is not a legal number\n", s.c_str());
	}
	if(ct>1) printf("The average of %d numbers is %.2lf", ct, sum / ct);
	else if(ct==1) printf("The average of 1 number is %.2lf", sum / ct);
	else printf("The average of 0 numbers is Undefined");
	return 0;
}