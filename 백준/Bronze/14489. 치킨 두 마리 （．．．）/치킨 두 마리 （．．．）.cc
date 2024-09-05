#include <iostream>
using namespace std;

int main(){
	long long int a, b, c;
	cin >> a >> b >> c;
	if (a + b - 2 * c >= 0) cout << a + b - 2 * c << endl;
	else cout << a + b << endl;
}