#include <iostream>
using namespace std;
int arr[26];
int main() { // 97~122  a~z

	string s; 
	cin >> s;
	string alpa;
	int index;
	int cnt = 0;
	
	alpa = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < alpa.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (alpa[i] == s[j]) {
				arr[i] = j;
				cnt++;
				break;
			}
			
		}
		if (cnt == 0) {
			arr[i] = -1;
		}
		cnt = 0;
	}
	for (int i = 0; i < alpa.size(); i++) {
		cout << arr[i] << ' ';
	}

}