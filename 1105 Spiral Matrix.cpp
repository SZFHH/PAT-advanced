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
int m, n, dir;
vector<vector<int>> ans;
vector<int> arr;
void next(int &i, int &j) {
	if (dir == 0 && (j == n - 1 || ans[i][j + 1])) dir = 1;
	else if (dir == 1 && (i == m - 1 || ans[i + 1][j])) dir = 2;
	else if (dir == 2 && (j == 0 || ans[i][j - 1]))dir = 3;
	else if (dir == 3 && (i == 0 || ans[i - 1][j])) dir = 0;

	if (dir == 0) j++;
	else if (dir == 1) i++;
	else if (dir == 2) j--;
	else i--;
}
int main()
{
	int k, i(0), j(0);
	cin >> k;
	arr.resize(k);
	n = sqrt(k);
	while (k%n) n--;
	m = k / n;
	for (int i = 0; i < m; ++i) ans.push_back(vector<int>(n));
	for (int i = 0; i < k; ++i) scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end(), greater<int>());
	for (int x = 0; x < k; ++x) {
		ans[i][j] = arr[x];
		next(i, j);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j != 0) cout << ' ';
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}