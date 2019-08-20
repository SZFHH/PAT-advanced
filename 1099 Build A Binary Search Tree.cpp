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
int tree[105][2];
int m_data[105];
int tree_data[105];
vector<int> ans, seq;
void inorder(int index) {
	if (tree[index][0] != -1) inorder(tree[index][0]);
	seq.push_back(index);
	if (tree[index][1] != -1) inorder(tree[index][1]);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) scanf("%d%d", &tree[i][0], &tree[i][1]);
	for (int i = 0; i < n; ++i) scanf("%d", &m_data[i]);
	sort(m_data, m_data + n);
	inorder(0);
	for (int i = 0; i < n; ++i) tree_data[seq[i]] = m_data[i];
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int par = q.front();
		q.pop();
		ans.push_back(tree_data[par]);
		if (tree[par][0] != -1) q.push(tree[par][0]);
		if (tree[par][1] != -1) q.push(tree[par][1]);
	}
	for (int i = 0; i < n; ++i) {
		if (i != 0) cout << ' ';
		cout << ans[i];
	}
	return 0;
}