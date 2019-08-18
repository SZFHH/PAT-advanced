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
int gcd(int m, int n) {
	return n == 0 ? m : gcd(n, m%n);
}
struct rat {
	int integr, nume, deno;
	int syb;
	rat() :integr(0), syb(1), nume(0),deno(1) {}
	void symp() {
		int g = gcd(nume, deno);
		nume /= g;
		deno /= g;
		integr += nume / deno;
		nume %= deno;
	}
	void resymp() {
		nume += integr*deno;
		integr = 0;
	}
	rat operator += (rat r) {
		rat rv;
		if (syb == r.syb) {
			rv.nume = nume*r.deno + r.nume*deno;
			rv.deno = deno*r.deno;
			rv.integr = integr + r.integr;
			rv.syb = syb;
			if (!rv.nume && !rv.integr) rv.syb = 1;
			
		}
		else if (syb > r.syb) {
			resymp();
			r.resymp();
			int newnume = nume*r.deno - r.nume*deno;
			if (newnume < 0) rv.syb = -1;
			else rv.syb = 1;
			rv.nume = abs(newnume);
			rv.deno = deno*r.deno;
		}
		else {
			rv = r += *this;
		}
		rv.symp();
		*this = rv;
		return rv;
	}
};
istream & operator >> (istream &in, rat & r) {
	r.integr = 0;
	r.syb = 1;
	scanf("%d/%d", &r.nume, &r.deno);
	if (r.nume < 0) {
		r.syb = -1;
		r.nume = -r.nume;
	}
	return in;
}
rat v;
int main()
{
	int n;
	cin >> n;
	rat sum;
	for (int i = 0; i < n; ++i){
		cin>>v;
		sum += v;
	}
	if (sum.syb == -1)cout << '-';
	if (!sum.integr && !sum.nume) cout << 0;
	else if (!sum.integr) cout << sum.nume << '/' << sum.deno;
	else if (!sum.nume) cout << sum.integr;
	else cout<<sum.integr<<' '<< sum.nume << '/' << sum.deno;
	return 0;
}