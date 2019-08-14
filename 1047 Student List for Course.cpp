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

unordered_multimap<int, string> ans;
vector<string> v;
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		string name;
		int num, cid;
		cin >> name;
		scanf("%d", &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &cid);
			ans.insert(make_pair(cid, name));
		}
	}
	for (int i = 1; i <= k; ++i) {
		pair<unordered_multimap<int, string>::iterator, unordered_multimap<int, string>::iterator> range = ans.equal_range(i);
		for (auto it = range.first; it != range.second; ++it) v.push_back(it->second);
		sort(v.begin(), v.end());
		printf("%d %d\n", i, v.size());
		for (auto &s : v) printf("%s\n", s.c_str());
		v.clear();
	}
	return 0;
}