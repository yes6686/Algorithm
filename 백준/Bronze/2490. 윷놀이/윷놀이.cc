#include <iostream>
using namespace std;
int arr[10];
int main() {

	
	int x;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> x;
			arr[x]++;
		}
		if (arr[0] == 0) {
			cout << "E" << endl;
		}
		else if (arr[1] == 0) {
			cout << "D" << endl;
		}
		else if (arr[0] == 2) {
			cout << "B" << endl;
		}
		else if (arr[0] == 1) {
			cout << "A" << endl;
		}
		else if(arr[0]==3) {
			cout << "C" << endl;
		}
		arr[0] = 0;
		arr[1] = 0;
	}

}