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

struct book {
	int id;
	string title, author, keywords, publisher;
	int year;
	bool operator<(book b) {
		return id < b.id;
	}
};
vector<book> books;
int main()
{
	int n;
	scanf("%d", &n);
	books.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &books[i].id);
		cin.get();
		getline(cin, books[i].title, '\n');
		getline(cin, books[i].author, '\n');
		getline(cin, books[i].keywords, '\n');
		getline(cin, books[i].publisher, '\n');
		scanf("%d", &books[i].year);
		cin.get();
	}
	sort(books.begin(), books.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int cmd, ct(0);
		string des;
		cin >> cmd;
		cin.get();
		cin.get();
		getline(cin, des, '\n');
		printf("%d: %s\n", cmd, des.c_str());
		if (cmd == 1) {
			for (auto &bk : books) {
				if (bk.title == des) {
					printf("%07d\n", bk.id);
					ct++;
				}
			}
		}
		else if (cmd == 2) {
			for (auto &bk : books) {
				if (bk.author == des) {
					printf("%07d\n", bk.id);
					ct++;
				}
			}
		}
		else if (cmd == 3) {
			for (auto &bk : books) {
				if (bk.keywords.find(des) != -1) {
					printf("%07d\n", bk.id);
					ct++;
				}	
			}
		}
		else if (cmd == 4) {
			for (auto &bk : books) {
				if (bk.publisher ==des){
					printf("%07d\n", bk.id);
					ct++;
				}
			}
		}
		else {
			int y = atoi(des.c_str());
			for (auto &bk : books) {
				if (bk.year == y){
					printf("%07d\n", bk.id);
					ct++;
				}
			}
		}
		if (ct == 0)
			printf("Not Found\n");
	}
	return 0;
}