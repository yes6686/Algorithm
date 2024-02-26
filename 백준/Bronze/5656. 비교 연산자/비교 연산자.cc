#include <iostream>
#include <string>
using namespace std;

int main() {
	int t = 1;
	while (1) {
		string s;
		getline(cin,s);
		int a;
		int b;
		int ss = 0;
		string k;
		for (int i = 0; i < 3; i++) {
			string kk = "";
			for (int j = ss; j < s.size(); j++) {
				ss++;
				if (s[j] == ' ') break;
				kk += s[j];
			}
			if (i == 0) {
				a = stoi(kk);
			}
			else if (i == 1) {
				k = kk;
			}
			else  {
				b = stoi(kk);
			}
		}
		if (k == "E") break;
		if (k == ">") {
			cout << "Case " << t << ": ";
			if (a > b) {
				cout << "true" << '\n';
			}
			else {
				cout << "false" << '\n';
			}
		}
		else if (k == ">=") {

			cout << "Case " << t << ": ";
			if (a >= b) {
				cout << "true" << '\n';
			}
			else {
				cout << "false" << '\n';
			}
		}
		else if (k == "<") {

			cout << "Case " << t << ": ";
			if (a < b) {
				cout << "true" << '\n';
			}
			else {
				cout << "false" << '\n';
			}
		}
		else if (k == "<=") {

			cout << "Case " << t << ": ";
			if (a <= b) {
				cout << "true" << '\n';
			}
			else {
				cout << "false" << '\n';
			}
		}
		else if (k == "==") {

			cout << "Case " << t << ": ";
			if (a == b) {
				cout << "true" << '\n';
			}
			else {
				cout << "false" << '\n';
			}
		}
		else {
			cout << "Case " << t << ": ";
			if (a != b) {
				cout << "true" << '\n';
			}
			else {
				cout << "false" << '\n';
			}
		}
		t++;
	}
}