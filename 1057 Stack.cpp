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

multiset<int> st;
vector<int> ans;
typedef multiset<int>::iterator sit;
int main()
{
	sit midit;
	bool isodd = false;
	char cmd[15];
	int n, data;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%s", cmd);
		if (cmd[1] == 'o') {
			if (ans.size()) {
				isodd = !isodd;
				data = ans[ans.size() - 1];
				printf("%d\n", data);
				ans.pop_back();
				sit dit = st.find(data);
				if (isodd && data <= *midit) midit++;
				else if (st.size() > 1 && !isodd && (data > *midit || (data == *midit && midit == dit))) midit--;
				st.erase(dit);
			}
			else printf("Invalid\n");
		}
		else if (cmd[1] == 'u') {
			isodd = !isodd;
			scanf("%d", &data);
			ans.push_back(data);
			st.insert(data);
			if (st.size() == 1) midit = st.begin();
			else if (isodd && data >= *midit) midit++;
			else if (!isodd && data < *midit) midit--;
		}
		else {
			if (ans.size()) printf("%d\n", *midit);
			else printf("Invalid\n");
		}
	}
	return 0;
}