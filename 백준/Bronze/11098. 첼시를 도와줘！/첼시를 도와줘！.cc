#include <iostream>
#include <algorithm>
using namespace std;

typedef struct player {
	int price;
	string name;

};

bool compare(player a, player b) {
	return a.price > b.price;
}


int main() {
	player p[101];
	int T;
	cin >> T;
	int n;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> p[i].price >> p[i].name;
		}
		sort(p, p + n, compare);
		cout << p[0].name << endl;
	}
	
}