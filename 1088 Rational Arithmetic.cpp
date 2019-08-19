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
int gcd(long int n, long int m) {
	return m == 0 ? n : gcd(m, n%m);
}
struct rat {
	long int syb;
	long int intg, nume, deno;
	rat() :syb(1), intg(0), nume(0), deno(1) {}
	void symp() {
		int g = gcd(nume, deno);
		nume /= g;
		deno /= g;
		intg += nume / deno;
		nume %= deno;
		if (!intg && !nume) syb = 1;
	}
	void rec() {
		nume += intg*deno;
		intg = 0;
	}
	rat operator +(rat r) {
		rat rv;
		if (r.syb == syb) {
			rv.syb = syb;
			rv.intg = intg + r.intg;
			rv.deno = deno * r.deno;
			rv.nume = deno*r.nume + nume * r.deno;
		}
		else if (syb > r.syb) {
			rec();
			r.rec();
			rv.deno = deno*r.deno;
			rv.nume = nume*r.deno - deno*r.nume;
			if (rv.nume < 0) {
				rv.nume = -rv.nume;
				rv.syb = -1;
			}
		}
		else {
			rv = r + (*this);
		}
		rv.symp();
		symp();
		r.symp();
		return rv;
	}
	rat operator-(rat r) {
		rat tmp = r;
		tmp.syb = -tmp.syb;
		return (*this) + tmp;
	}
	rat operator*(rat r) {
		rat rv;
		rec();
		r.rec();
		rv.syb = syb*r.syb;
		rv.deno = deno*r.deno;
		rv.nume = nume*r.nume;
		rv.symp();
		symp();
		r.symp();
		return rv;
	}
	rat operator/(rat r) {
		rat tmp = r;
		tmp.rec();
		swap(tmp.deno, tmp.nume);
		return (*this)*tmp;
	}
	void show() const {
		if (syb == -1) cout << "(-";
		if (!nume && !intg) cout << 0;
		else if (!nume) cout << intg;
		else if (!intg) cout << nume << '/' << deno;
		else cout << intg << ' ' << nume << '/' << deno;
		if (syb == -1) cout << ')';
	}
	void reset() {
		syb = 1, intg = 0, nume = 0, deno = 1;
	}
	bool iszero() { return !nume && !intg; }
};
istream & operator >> (istream &in, rat & r) {
	r.reset();
	scanf("%ld/%ld", &r.nume, &r.deno);
	if (r.nume < 0) {
		r.nume = -r.nume;
		r.syb = -1;
	}
	r.symp();
	return in;
}
ostream & operator << (ostream &o, const rat & r) {
	r.show();
	return o;
}
int main()
{
	rat r1, r2;
	cin >> r1 >> r2;
	cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
	cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
	cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
	cout << r1 << " / " << r2 << " = ";
	if (!r2.iszero()) cout << r1 / r2;
	else cout << "Inf" << endl;
	return 0;
}