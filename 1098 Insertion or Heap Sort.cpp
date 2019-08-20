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
int n;
int ori[105], cur[105];
int isinsert() {
	int i = 1;
	while (cur[i] >= cur[i - 1]) ++i;
	for (int j = i; j < n; ++j) {
		if (ori[j] != cur[j]) return 0;
	}
	return i;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> ori[i];
	for (int i = 0; i < n; ++i) cin >> cur[i];
	int k;
	if (k = isinsert()) {
		int data = cur[k], i;
		for (i = k - 1; i >= 0; --i) {
			if (cur[i] > data) cur[i + 1] = cur[i];
			else break;
		}
		cur[i + 1] = data;
		cout << "Insertion Sort" << endl;
	}
	else {
		int data = cur[0], last = n - 1, next=1, par = 0;
		while (cur[last] >= data) --last;
		swap(cur[0], cur[last]);
		data = cur[0];
		while (next < last) {
			if (next + 1 < last && cur[next] < cur[next + 1]) next++;
			if (cur[next] > data) cur[par] = cur[next];
			else break;
			par = next;
			next = 2 * par + 1;
		}
		cur[par] = data;
		cout << "Heap Sort" << endl;

	}
	for (int i = 0; i < n; ++i) {
		if (i != 0) cout << ' ';
		cout << cur[i];
	}
	return 0;
}