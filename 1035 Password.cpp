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
struct info {
	string id, psw;
};
vector<info> t;
bool modify(string & s) {
	bool flag = false;
	for (auto &c : s) {
		if (c == '1') c = '@', flag = true;
		else if (c == '0') c = '%', flag = true;
		else if (c == 'l') c = 'L', flag = true;
		else if (c == 'O') c = 'o', flag = true;
	}
	return flag;
}
int main()
{
	int n, ct = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string id, psw;
		cin >> id >> psw;
		t.push_back(info{ id,psw });
	}
	for (auto & tt : t) {
		if (modify(tt.psw)) ct++;
		else tt.id = "NULL";
	}
	if (ct == 0) {
		if (n == 1)
			cout << "There is 1 account and no account is modified" << endl;
		else
			printf("There are %d accounts and no account is modified\n", n);
	}
	else{
		cout << ct << endl;
		for (auto & tt : t) {
			if (tt.id != "NULL") cout << tt.id << ' ' << tt.psw << endl;
		}
	}
	return 0;
}