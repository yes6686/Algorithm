#include <iostream>
using namespace std;

int N;

int main() {
	cin >> N;
	if (N != 1 && N != 3) {
		cout << "EI";
		return 0;
	}
	cin >> N;
	if (N != 6 && N != 8) {
		cout << "EI";
		return 0;
	}
	cin >> N;
	if (N != 2 && N != 5) {
		cout << "EI";
		return 0;
	}
	cout << "JAH";
}