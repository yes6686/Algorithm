#include <iostream>
#include <math.h>
using namespace std;
int main() { //A~Z  65~90  10~35
	
	string n;
	int B;
	cin >> n>>B;
	int len = n.length();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (n[i] - '0' >= 10) {
			sum += (n[i] - 55) * (pow(B, len - i-1));
		}
		else {
			sum += (n[i] - '0') * (pow(B, len - i - 1));
		}
	}
	cout << sum;

}