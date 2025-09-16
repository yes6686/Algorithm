#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		
		string s1;
		cin >> s1;

		string s2 = "";
		for (int i = s1.size()-1;i >= 0;i--) {
			s2 += s1[i];
		}

		int sum = stoi(s1) + stoi(s2);

		string s3 = to_string(sum);

		int check = 1;
		for (int i = 0;i < s3.size()/2;i++) {
			if (s3[i] != s3[s3.size() - 1 - i]) check = 0;
		}

		if (check == 1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}	
}