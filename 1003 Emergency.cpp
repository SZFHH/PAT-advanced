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
#include<set>
#include<limits.h>
using namespace std;

int gp[505][505];
int hand[505];
int hasvisted[505];
int getmin(int dis[], int n) {
	int min = INT_MAX;
	int mini = -1;
	for (int i = 0; i < n; ++i) {
		if (!hasvisted[i] && dis[i] < min) {
			mini = i;
			min = dis[i];
		}
	}
	return mini;
}

int main()
{
	for (int i = 0; i < 505; i++)
		for (int j = 0; j < 505; j++)
			gp[i][j] = -1;
	int n, r, sc, ec;
	cin >> n >> r >> sc >> ec;
	for (int i = 0; i < n; ++i)
		cin >> hand[i];
	for (int i = 0; i < r; ++i) {
		int c1, c2, len;
		scanf("%d%d%d", &c1, &c2, &len);
		//cin >> c1 >> c2 >> len;
		gp[c1][c2] = len;
		gp[c2][c1] = len;
	}
	int maxhand[505];
	int dist[505], roadnums[505];

	maxhand[sc] = hand[sc];
	memset(roadnums, 0, sizeof(roadnums));
	roadnums[sc] = 1;
	for (int i = 0; i < 505; ++i)
		dist[i] = INT_MAX;
	dist[sc] = 0;
	int curc = sc;

	while (curc != ec) {
		curc = getmin(dist, n);
		hasvisted[curc] = 1;
		for (int i = 0; i < n; ++i) {
			if (gp[curc][i] >= 0 && !hasvisted[i])
			{
				if (dist[i] > dist[curc] + gp[curc][i]) {
					dist[i] = dist[curc] + gp[curc][i];
					roadnums[i] = roadnums[curc];
					maxhand[i] = maxhand[curc] + hand[i];
				}
				else if (dist[i] == dist[curc] + gp[curc][i]) {
					roadnums[i] += roadnums[curc];
					maxhand[i] = max(maxhand[i], maxhand[curc] + hand[i]);
				}

			}
		}
	}

	/*printf("%d %d", roadnums[ec], maxhand[ec]);*/
	cout << roadnums[ec] << ' ' << maxhand[ec];
	return 0;
}
