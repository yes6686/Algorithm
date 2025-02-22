#include <iostream>
#include <string>
using namespace std;
int main(){
	int vote;
	cin >> vote;
	for (int i = 0; i < vote; i++) {
		int n;
		string result;
		cin >> n;
		for (int j = 0; j < n / 5; j++) {
			result = result + "++++ ";
		}

		for (int j = 0; j < n % 5; j++) {
			result = result + "|";
		}
		cout << result<<"\n"; 
	}
}