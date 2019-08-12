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

int m_next[100005];
int v[100005];
int main()
{
	int a, b, n, tmp(0);
	char c;
	cin >> a >> b >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		cin >> c >> m_next[tmp];
	}
	while (a != -1){
		v[a] = true;
		a = m_next[a];
	}
	while (b != -1) {
		if (v[b]){
			printf("%05d", b);
			return 0;
		}
		b = m_next[b];
	}
	cout << -1;
	return 0;
}