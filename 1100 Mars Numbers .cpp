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

string lo[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string hi[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
map<string, int> hi2id, lo2id;
int main()
{
	for (int i = 0; i <= 12; ++i) {
		hi2id[hi[i]] = i;
		lo2id[lo[i]] = i;
	}
	int n;
	cin >> n;
	cin.get();
	string s;
	for (int i = 0; i < n; ++i) {
		getline(cin, s, '\n');
		if (isdigit(s[0])) {
			int num = atoi(s.c_str()), high, low;
			high = num / 13;
			low = num % 13;
			if (!high && !low) cout << "tret" << endl;
			else if (!high) cout << lo[low] << endl;
			else if (!low) cout << hi[high] << endl;
			else cout << hi[high] << ' ' << lo[low] << endl;
		}
		else {
			string high("tret"), low("tret");
			int index = s.find(' ');
			if (index != -1) {
				high = s.substr(0, index);
				low = s.substr(index + 1, s.size() - index - 1);
			}
			else {
				if (hi2id.find(s) != hi2id.end()) high = s;
				else low = s;
			}
			cout << hi2id[high] * 13 + lo2id[low] << endl;
		}
	}
	return 0;
}