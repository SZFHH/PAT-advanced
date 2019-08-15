# include <iostream>
# include <functional>
# include <vector>
# include <algorithm>
#include<math.h>
#include<string>
#include<cstring>
#include<iterator>
#include<iomanip>
using namespace std;
int N, L, H;
struct candidate {
	int id;
	int mrl;
	int abt;
	bool operator<(candidate c) {
		if ((mrl >= H&&abt >= H) && (c.abt < H || c.mrl < H))
			return true;
		else if ((mrl >= H&&abt >= H) && (c.abt >= H && c.mrl >= H)) {
			if (mrl + abt < c.mrl + c.abt)
				return false;
			else if (mrl + abt > c.mrl + c.abt)
				return true;
			else {
				if (mrl < c.mrl)
					return false;
				else if (mrl > c.mrl)
					return true;
				else
					return id < c.id;
			}
		}
		else if ((mrl < H || abt < H) && (c.abt >= H && c.mrl >= H))
			return false;
		else if ((mrl >= H) && (c.mrl < H))
			return true;
		else if ((mrl >= H) && (c.mrl >= H)) {
			if (mrl + abt < c.mrl + c.abt)
				return false;
			else if (mrl + abt > c.mrl + c.abt)
				return true;
			else {
				if (mrl < c.mrl)
					return false;
				else if (mrl > c.mrl)
					return true;
				else
					return id < c.id;
			}
		}
		else if (mrl < H&&c.mrl >= H)
			return false;
		else if ((mrl >= abt) && (c.mrl < c.abt))
			return true;
		else if ((mrl >= abt) && (c.mrl >= abt)) {
			if (mrl + abt < c.mrl + c.abt)
				return false;
			else if (mrl + abt > c.mrl + c.abt)
				return true;
			else {
				if (mrl < c.mrl)
					return false;
				else if (mrl > c.mrl)
					return true;
				else
					return id < c.id;
			}
		}
		else if ((mrl < abt) && (c.mrl >= c.abt))
			return false;
		else {
			if (mrl + abt < c.mrl + c.abt)
				return false;
			else if (mrl + abt > c.mrl + c.abt)
				return true;
			else {
				if (mrl < c.mrl)
					return false;
				else if (mrl > c.mrl)
					return true;
				else
					return id < c.id;
			}
		}

	}
};
int main(void)
{
	cin >> N >> L >> H;
	vector<candidate> arr;
	for (int i = 0; i < N; ++i) {
		candidate tmp;
		cin >> tmp.id >> tmp.mrl >> tmp.abt;
		if (tmp.mrl >= L&&tmp.abt >= L)
			arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	cout << arr.size() << endl;
	for (auto &c : arr) {
		cout << c.id << ' ' << c.mrl << ' ' << c.abt << endl;
	}
	return 0;
}
