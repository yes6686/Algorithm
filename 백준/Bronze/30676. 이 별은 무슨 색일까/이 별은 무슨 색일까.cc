#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	while (true) {
		if (x >= 380 && x <= 780)
			break;
	}
	if (x >= 620 && x <= 780)
		cout << "Red";
	else if (x >= 590 && x < 620)
		cout << "Orange";
	else if (x >= 570 && x < 590)
		cout << "Yellow";
	else if (x >= 495 && x < 570)
		cout << "Green";
	else if (x >= 450 && x < 495)
		cout << "Blue";
	else if (x >= 425 && x < 450)
		cout << "Indigo";
	else
		cout << "Violet";
}