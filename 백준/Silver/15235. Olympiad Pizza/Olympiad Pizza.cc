#include <iostream>
using namespace std;

int arr[1001];
int cnt[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	int count = 0;
	while (true) {
		int check = 0;

		for (int i = 0;i < n;i++) {
			if (arr[i] != 0) {
				check = 1;
				count++;
				arr[i]--;
				cnt[i] = count;
			}
		}
		if (check == 0) {
			break;
		}
	}

	for (int i = 0;i < n;i++) {
		cout << cnt[i] << ' ';
	}
}