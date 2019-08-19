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
int n;
int ori[105];
int cur[105];
int isinsert() {
	int i = 1;
	while (cur[i] >= cur[i - 1]) i++;
	for (int j = i; j < n; ++j) {
		if (ori[j] != cur[j]) return 0;
	}
	return i;
}
bool issorted(int s, int e) {
	for (int i = s + 1; i < e; ++i) {
		if (cur[i] < cur[i - 1]) return false;
	}
	return true;
}
bool isallsorted(int s) {
	for (int i = 0; i < n; i += s) {
		int end = i + s < n ? i + s : n;
		if (!issorted(i, end)) return false;
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> ori[i];
	for (int i = 0; i < n; ++i) cin >> cur[i];
	int i;
	if (i = isinsert()) {
		int data = cur[i], j = i - 1;
		for (; j >= 0 && cur[j] > data; --j) cur[j + 1] = cur[j];
		cur[j + 1] = data;
		cout << "Insertion Sort" << endl;
	}
	else {
		int s = 2;
		for (; isallsorted(s); s *= 2);
		for (int i = 0; i  < n; i += s) {
			int end = i + s < n ? i + s : n;
			sort(cur + i, cur + end);
		}
		cout << "Merge Sort" << endl;
	}
	for (int i = 0; i < n; ++i) {
		if (i != 0) cout << ' ';
		cout << cur[i];
	}
	return 0;
}