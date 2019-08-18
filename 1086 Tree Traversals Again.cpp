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
vector<int> ans;
vector<int> pre, in;
void post(int root, int left, int right) {
	if (left > right) return;
	int rt = pre[root], i = left;
	ans.push_back(rt);
	while (i < right && in[i] != rt) ++i;
	post(root+i-left+1, i + 1, right);
	post(root+1, left, i - 1);
}
int main()
{
	stack<int> s;
	int n, num;
	cin >> n;
	string cmd;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> cmd;
		if (cmd[1] == 'u') {
			cin >> num;
			s.push(num);
			pre.push_back(num);
		}
		else{
			num = s.top();
			in.push_back(num);
			s.pop();
		}
	}
	post(0, 0, n - 1);
	for (int i = n-1; i >= 0; --i) {
		cout << ans[i];
		if (i != 0) cout << ' ';
	}
	return 0;
}