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
string nums[13] = { "1","2","3","4","5","6","7","8","9","10","11","12","13" };
string syb[4] = { "S","H","C","D" };
vector<string> ans, m_buf(54);
int pos[54];
int main()
{
	for (int i = 0; i < 4; ++i) 
		for (int j = 0; j < 13; ++j) 
			ans.push_back(syb[i] + nums[j]);

	ans.push_back("J1");
	ans.push_back("J2");
	int n;
	cin >> n;
	for (int i = 0; i < 54; ++i) {
		cin >> pos[i];
		pos[i]--;
	}
	vector<string>* formal = &ans, *back = &m_buf;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < 54; ++i)
			(*back)[pos[i]] = (*formal)[i];
		swap(formal, back);
	}
	for (int i = 0; i < 54; ++i){
		if (i != 0) cout << ' ';
		cout << (*formal)[i];
	}
	return 0;
}