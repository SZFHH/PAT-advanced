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
multimap<string, int> ans;
typedef multimap<string, int>::iterator ansit;
vector<int> v;
int main()
{
	int n, m;
	cin >> n >> m;
	string name;
	for (int i = 0; i < m; ++i) {
		int cid, k;
		scanf("%d%d", &cid, &k);
		for (int j = 0; j < k; ++j) {
			cin >> name;
			ans.insert(make_pair(name, cid));
		}
	}
	for (int i = 0; i < n; ++i) {
		cin >> name;
		v.clear();
		pair<ansit, ansit> range = ans.equal_range(name);
		for (auto it = range.first; it != range.second; ++it)
			v.push_back(it->second);
		sort(v.begin(), v.end());
		printf("%s %d", name.c_str(), v.size());
		for (int i = 0; i < v.size(); ++i) printf(" %d", v[i]);
		printf("\n");
	}
	return 0;
}