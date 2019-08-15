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
int m_size;
void fill(string & s, int size) {
	reverse(s.begin(), s.end());
	for (int i = s.size(); i < size; ++i) s.push_back('0');
	reverse(s.begin(), s.end());
}
string sadd(const string &s1, const string &s2) {
	string rv;
	int last = 0;
	for (int i = s1.size() - 1; i >= 0; --i) {
		int ct = s1[i] - '0' + s2[i] - '0' + last;
		last = ct / 10;
		ct %= 10;
		rv.push_back(ct + '0');
	}
	if (last) rv.push_back('1');
	reverse(rv.begin(), rv.end());
	return rv;
}
string sminus(const string &s1, const string &s2) {
	if (s1 < s2) return sminus(s2, s1);
	string rv;
	int last = 0;
	for (int i = s1.size() - 1; i >= 0; --i) {
		int ct = s1[i] - last - s2[i];
		if (ct < 0) {
			last = 1;
			ct += 10;
		}
		else last = 0;
		rv.push_back(ct + '0');
	}
	reverse(rv.begin(), rv.end());
	return rv;
}
struct num {
	string ab;
	int syb;
	num(const string &s) {
		if (s[0] == '-') {
			syb = -1;
			ab = s.substr(1, s.size() - 1);
		}
		else {
			syb = 1;
			ab = s;
		}
		fill(ab, m_size);
	}
	bool operator>(num n) {
		int size = max(ab.size(), n.ab.size());
		fill(ab, size); fill(n.ab, size);
		if (syb > n.syb) return true;
		else if (syb == n.syb && syb == 1) return ab > n.ab;
		else if (syb == n.syb && syb == -1) return ab < n.ab;
		else return false;
	}
	num operator+(num n) {
		struct num rv("");
		if (syb == n.syb) {
			rv.ab = sadd(ab, n.ab);
			rv.syb = syb;
		}
		else if (syb > n.syb) {
			if (ab >= n.ab) rv.syb = 1;
			else rv.syb = -1;
			rv.ab = sminus(ab, n.ab);
		}
		else {
			return n.operator+(*this);
		}
		return rv;
	}
};

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		string a, b, c;
		cin >> a >> b >> c;
		m_size = max(max(a.size(), b.size()), c.size());
		num n1(a), n2(b), n3(c);
		if (n1 + n2 > n3) printf("true\n");
		else printf("false\n");
	}
	return 0;
}