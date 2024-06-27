#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int limitSpeed, speed;
	cin >> limitSpeed >> speed;

	if (limitSpeed >= speed) {
		cout << "Congratulations, you are within the speed limit!" << '\n';
	}
	else {
		int aboveSpeed = speed - limitSpeed;
		if (aboveSpeed <=20) {
			cout << "You are speeding and your fine is $100." << '\n';
		}
		else if (aboveSpeed <=30) {
			cout << "You are speeding and your fine is $270." << '\n';
		}
		else {
			cout << "You are speeding and your fine is $500." << '\n';
		}
	}
}