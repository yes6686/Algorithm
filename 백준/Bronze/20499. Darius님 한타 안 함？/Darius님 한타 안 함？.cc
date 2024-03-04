#include <iostream>
#include <string>
using namespace std;

int arr[3];

int main() {
	string s;
	cin >> s;
	int t = 0;
	string k = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '/') {
			arr[t] = stoi(k);
			t++;
			k = "";
		}
		else {
			k += s[i];
		}
	}
	arr[t] = stoi(k);
	if (arr[0] + arr[2] < arr[1] || arr[1] == 0) {
		cout << "hasu";
	}
	else {
		cout << "gosu";
	}
}