#include <iostream>

using namespace std;



int main() {
	
	string n;
	while (true) {
		cin >> n;
		int cnt = 0;
		if (n == "0") {	break;	}
		for (int i = 0; i < n.length() / 2; i++) {
			if (n[i] != n[n.length() - 1 - i]) {
				cnt++;
				break;
			}
		}
		if (cnt == 0) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		
		
	}
}