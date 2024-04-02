#include <iostream>
using namespace std;

int arr[21];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p;
	cin >> p;
	int T;

	while (p--) {
		cin >> T;
		for (int i = 0; i < 20; i++) {
			cin >> arr[i];
		}
		int cnt = 0;
		for (int i = 1; i < 20; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[j] > arr[i]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					cnt++;

				}
			}
		}
	
		cout << T << ' ' << cnt << '\n';
	


	}

}