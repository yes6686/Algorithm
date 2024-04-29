#include <iostream>
using namespace std;

int arr1[10];
int arr2[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 9; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < 9; i++) {
		cin >> arr2[i];
	}
	int s1 = 0;
	int s2 = 0;
	int check = 0;

	for (int i = 0; i < 9; i++) {
		s1 += arr1[i];
		if (s1 > s2) {
			check = 1;
			break;
		}
		s2 += arr2[i];
	}

	if (check == 1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}