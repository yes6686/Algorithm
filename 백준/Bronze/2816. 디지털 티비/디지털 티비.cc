#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int kbs1Location; // KBS1 위치
	int kbs2Location; // KBS2 위치
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "KBS1") {
			kbs1Location = i;
		}
		if (s == "KBS2") {
			kbs2Location = i;
		}
	}
	for (int i = 0; i < kbs1Location; i++) {
		cout << "1";
	}
	for (int i = 0; i < kbs1Location; i++) {
		cout << "4";
	}
	if (kbs1Location > kbs2Location) {
		kbs2Location += 1;
	}
	for (int i = 0; i < kbs2Location; i++) {
		cout << "1";
	}
	for (int i = 0; i < kbs2Location-1; i++) {
		cout << "4";
	}
}