#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
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
struct node {
	int index, value;
};
bool cmp(node a, node b) {
	return a.index < b.index;
}
vector<int> post, in;
vector<node> ans;
vector<vector<int>>level(30);
void getpre(int left, int right, int inleft, int depth);
void pre(int root, int left, int right, int index);
int n;
int main()
{
	cin >> n;
	post.resize(n);
	in.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> post[i];
	for (int i = 0; i < n; ++i)
		cin >> in[i];
	//getpre(0, n - 1, 0,0);
	pre(n - 1, 0, n - 1, 1);
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) cout << " ";
		cout << ans[i].value;
	}
	//int i = 0, count = 0,j;
	//while (level[i].size()) {//²ã´ÎÊä³ö
	//	for (j = 0; j<level[i].size(); ++j) {
	//		printf("%d", level[i][j]);
	//		if (count<n - 1)printf(" ");
	//		++count;
	//	}
	//	++i;
	//}
	return 0;
}

//void getpre(int left, int right, int inleft, int depth)
//{
//	if (left > right)
//		return;
//	level[depth].push_back(post[right]);
//	int index = find(in.begin(), in.begin()+n, post[right])-in.begin()- inleft;
//	getpre(left, left+index-1, inleft, depth +1);
//	getpre(left + index, right-1, inleft +index+1, depth + 1);
//}

void pre(int root, int left, int right, int index) {
	if (left > right)
		return;
	ans.push_back({ index,post[root] });
	int i = left;
	while (i <= right && in[i] != post[root]) i++;
	pre(root - 1 - right + i, left, i - 1, index * 2);
	pre(root - 1, i + 1, right, index * 2 + 1);
}