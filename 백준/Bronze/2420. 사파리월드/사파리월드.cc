#include <iostream>
using namespace std;


int main() {

	long long int n, m;
	cin >> n >> m;
	long long int result = n - m;

	if (n - m < 0) {
		cout << result*(- 1)<< endl;
	}
	else {
		cout << result << endl;
	}


	
	
}