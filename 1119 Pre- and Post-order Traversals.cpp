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

vector<int> ans;
int pre[35], post[35];
bool m_unique = true;
int n;
void in(int pres, int pree, int posts, int poste) {
	if (pres == pree) {
		ans.push_back(pre[pres]);
		return;
	}
	int i = pres;
	while (i < pree && pre[i] != post[poste - 1]) ++i;
	if (i - pres > 1)
		in(pres + 1, i - 1, posts, posts - pres + i - 2);
	else
		m_unique = false;
	ans.push_back(post[poste]);
	in(i, pree, posts - pres + i - 1, poste - 1);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> pre[i];
	for (int i = 0; i < n; ++i) cin >> post[i];
	in(0, n - 1, 0, n - 1);
	if (m_unique) cout << "Yes" << endl;
	else cout << "No" << endl;
	for (int i = 0; i < ans.size(); ++i) {
		if (i != 0) cout << ' ';
		cout << ans[i];
	}
	cout << endl;
	return 0;
}