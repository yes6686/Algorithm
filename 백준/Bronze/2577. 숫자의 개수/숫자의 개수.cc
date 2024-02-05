#include <iostream>
using namespace std;
int arr[10];
int main() {
	
	int  a, b, c;
	cin >> a >> b >> c; 
	
	int num = a * b * c; // 17037300

	for (int i = num; i > 0; i /= 10) {
		arr[i % 10]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}


}