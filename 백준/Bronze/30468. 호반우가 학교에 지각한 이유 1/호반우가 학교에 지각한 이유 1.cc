#include <iostream>
using namespace std;

int main() {
	int STR, DEX, INT, LUK, n;
	cin >> STR >> DEX >> INT >> LUK>>n;
	int av = (STR + DEX + INT + LUK) / 4;
	int cnt = 0;
	while (1) {
		if (av >= n) {
			break;
		}
		INT++; 
		cnt++;
		av = (STR + DEX + INT + LUK) / 4;

	}
	cout << cnt;
}