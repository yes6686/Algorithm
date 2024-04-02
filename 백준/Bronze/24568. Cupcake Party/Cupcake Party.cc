#include <iostream>
using namespace std;
int main() {
	int r, s;
	cin >> r >> s;
	int cupCakeCount = r * 8 + s * 3;
	if (cupCakeCount - 28 <= 0) {
		cout << 0;
	}
	else {
		cout << cupCakeCount - 28;
	}

}