#include <iostream>
using namespace std;

int main(void){
	double a, b;
	cin >> a >> b;
	if (a / b < 0.2) cout << "weak";
	else if (a / b < 0.4) cout << "normal";
	else if (a / b < 0.6) cout << "strong";
	else cout << "very strong";
}