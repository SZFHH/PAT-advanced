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
struct node {
	int i, j, h;
};
int n, m, k, d;
int sum, ct;
int arr[1290][130][61];
int idiff[6] = { 0,-1,0,1,0,0 };
int jdiff[6] = { -1,0,1,0,0,0 };
int hdiff[6] = { 0,0,0,0,1,-1 };
bool legal(int i, int j, int h) {
	return i >= 0 && i < n&&j >= 0 && j < m&&h >= 0 && h < k;
}
void FDT(int i, int j, int h) {
	arr[i][j][h] = 0;
	ct++;
	for (int x = 0; x < 6; ++x) {
		int newi = i + idiff[x], newj = j + jdiff[x], newh = h + hdiff[x];
		if (legal(newi, newj, newh) && arr[newi][newj][newh]) FDT(newi, newj, newh);
	}
}
void BFS(int i, int j, int h) {
	queue<node> q;
	q.push(node{ i,j,h });
	arr[i][j][h] = 0;
	ct++;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		for (int x = 0; x < 6; ++x) {
			int newi = cur.i + idiff[x], newj = cur.j + jdiff[x], newh = cur.h + hdiff[x];
			if (legal(newi, newj, newh) && arr[newi][newj][newh]) {
				q.push(node{ newi,newj,newh });
				arr[newi][newj][newh] = 0;
				ct++;
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &d);
	for (int i = 0; i < k; ++i) 
		for (int j = 0; j < n; ++j) 
			for (int x = 0; x < m; ++x) 
				scanf("%d", &arr[j][x][i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int h = 0; h < k; ++h) {
				if (arr[i][j][h]) BFS(i, j, h);
				if (ct >= d) sum += ct;
				ct = 0;
			}
		}
	}
	cout << sum;
	return 0;
}