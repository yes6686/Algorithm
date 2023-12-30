#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int go(string n,int x) {
	int ans = 0;
	for (int i = 0; i < n.size(); i++) {

		if (n[i] - '0' > x) {
			if (i == 0) {
				if (x == 0) continue;
				ans += pow(10, n.size()-i-1);
			}
			else {
				string k = "";
				for (int j = 0; j < i; j++) {
					k += n[j];
				}
				if (x == 0) {
					ans += (stoi(k) * pow(10, n.size() - i - 1));
				}
				else {
					ans += ((stoi(k) + 1) * pow(10, n.size() - i - 1));
				}
			}
		}
		else if (n[i] - '0' == x) {
			if (i == 0) {
				for (int i = 1; i < n.size(); i++) {
					ans += pow(10, n.size()-i-1)*(n[i]-'0');
				}
				ans += 1;
			}
			else if (i == n.size() - 1) {
				string k = "";
				for (int j = 0; j < i; j++) {
					k += n[j];
				}
				if (x == 0) {
					ans += stoi(k);
				}
				else
					ans += stoi(k) + 1;
			}
			else {
				string k = "";
				for (int j = 0; j < i; j++) {
					k += n[j];
				}
				int kk = 0;
				kk += pow(10, n.size() - i - 1);
				if (x == 0) {
					kk *= stoi(k)-1;
				}
				else
					kk *= stoi(k);
				ans += kk;
				k = "";
				for (int j = i+1; j < n.size(); j++) {
					k += n[j];
				}
				/*if (x == 0) {
					ans += stoi(k);
				}
				else*/
					ans += stoi(k) + 1;
			}
		}
		else {
			if (i == 0) continue;
			string k = "";
			for (int j = 0; j < i; j++) {
				k += n[j];
			}

			ans += (pow(10, n.size() - i - 1)*(stoi(k)));
		}
	}
	return ans;
}


int main() {

	string n;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		cout << go(n, i) << ' ';
	}
}