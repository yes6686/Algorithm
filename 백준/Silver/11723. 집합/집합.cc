#include <iostream>
using namespace std;
int arr[21];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	string a;
	int x;
	while (T--) {
		cin >> a;
		if (a == "add") {
			cin >> x;
			arr[x] = 1;
			
		}
		else if (a == "remove") {
			cin >> x;
			arr[x] = 0;
		}
		else if (a == "check") {
			cin >> x;
			if (arr[x] == 1) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (a == "toggle") {
			cin >> x;
			if (arr[x] == 1) {
				arr[x] = 0;
			}
			else {
				arr[x] = 1;
			}
		}
		else if (a == "all") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 0;
			}
			for (int i = 1; i <= 20; i++) {
				arr[i] = 1;
			}
		}
		else if (a == "empty") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 0;
			}
		}
	}
		
}

	
