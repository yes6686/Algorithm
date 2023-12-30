#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque<int>d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	string s, x;
	int n;
	while (T--) {
		cin >> s;
		cin >> n;
		cin >> x;
		string k = "";
		for (int i = 1; i <x.size(); i++) {
			if (x[i] == ',' || x[i]==']') {
				if (k == "") continue;
				d.push_back(stoi(k));
				k = "";
			}
			else {
				k += x[i];
			}
		}
		int kk = 0;
		int errorCheck = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R') {
				if (d.size() == 0) {
					continue;
				}
				kk = kk == 1 ? 0 : 1;
			}
			else {
				if (d.size() == 0) {
					cout << "error" << '\n';
					errorCheck = 1;
					break;
				}
				else {
					if (kk == 0) {
						d.pop_front();
					}
					else {
						d.pop_back();
					}
				}
			}
		}
		if (errorCheck) {
			continue;
		}
		cout << "[";
		while (d.size() > 1) {
			if (kk == 0) {
				cout << d.front();
				cout << ",";
				d.pop_front();
			}
			else {
				cout << d.back();
				cout << ",";
				d.pop_back();
			}
		}
		if (d.size()) {
			cout << d.back();
			d.pop_back();
		}
		cout << "]" << '\n';
	}
}