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

int n, k, p, m, n2;
int value[401][401][22]; //��¼factor�ĺͣ�������Ϊ0������λ�ö�Ӧn��k��m��m��С��n��ƽ�������������20��
int res[401][401][22]; //��¼���������ÿ�����ֵĴ���
vector<int> items, ans;
int main()
{
	cin >> n >> k >> p;
	n2 = n;
	int item = 0;
	for (int i = 1; item <= n; i++) {
		items.push_back(item);
		item = pow(i, p);
	}
	m = items.size() - 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			for (int x = 1; x <= m; ++x) {
				if (items[x] > i) {
					value[i][j][x] = value[i][j][x - 1];
				}
				else {
					int w = i - items[x], ct(j - 1), maxv(value[i][j][x - 1]), inc = x;
					for (; w >= 0 && ct >= 0 ; w -= items[x], ct--, inc+=x) {
						if (value[w][ct][x] || (!w && !ct)) {
							if (value[w][ct][x] + inc >= maxv) { //����һ��Ҫ��������Ȼû��ͳ�ƽ����
								res[i][j][x] = j - ct;
								maxv = value[w][ct][x] + inc;
							}
						}
					}
					value[i][j][x] = maxv;
				}
			}
		}
	}
	if (!value[n][k][m]) {
		printf("Impossible");
		return 0;
	}
	while (k) {
		for (; m >= 1; --m) {
			if (res[n][k][m]) break;
		}
		int times = res[n][k][m];
		for (int x = 0; x < times; ++x) ans.push_back(m);
		k -= times;
		n -= items[m]* times;
		--m;
	}
	printf("%d = ", n2);
	for (int i = 0; i < ans.size(); ++i) {
		if (i != 0) printf(" + ");
		printf("%d^%d", ans[i], p);
	}
	return 0;
}