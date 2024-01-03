#include <iostream>

using namespace std;

struct student {
	int weigth;
	int height;
};

int main() {
	int n;
	cin >> n;
	student k[51];
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		cin >> k[i].weigth >> k[i].height;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (k[i].weigth < k[j].weigth && k[i].height < k[j].height) {
				cnt++;
			}
		}
		cout << cnt << ' ';
		cnt = 1;
	}
	

}