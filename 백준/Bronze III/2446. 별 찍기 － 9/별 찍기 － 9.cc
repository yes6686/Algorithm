#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) { //0 1 2 3 4
			cout << " ";
		}
		for (int j = 0; j < n-i-1; j++) { //4 3 2 1 0
			cout << "*";
		}
		cout << "*";
		for (int j = 0; j < n-i-1; j++) { // 4 3 2 1 0 
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-2; j++) { // 3 2 1 0
			cout << " ";
		}
		for (int j = 0; j < i+1; j++) { //1 2 3 4
			cout << "*";
		}
		cout << "*";
		for (int j = 0; j < i+1; j++) { // 1 2 3 4
			cout << "*";
		}
		cout << endl;
	}
}