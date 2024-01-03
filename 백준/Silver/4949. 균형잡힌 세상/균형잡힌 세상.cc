#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		string s;
		stack<char>a;
		int check = 1;
		getline(cin,s);
		if (s == ".") {
			break;
		}
		else {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '(' || s[i] == '[') {
					a.push(s[i]);
				}
				else if (s[i] == ')') {
					if (a.empty()==1) {
						check = 0;
						break;
					}
					else if (a.top() == '(') {
						a.pop();
					}
					else if (a.top() == '[') {
						check = 0;
						break;
					}

				}
				else if (s[i] == ']') {
					if (a.empty()==1) {
						check = 0;
						break;
					}
					else if (a.top() == '[') {
						a.pop();
					}
					else if (a.top() == '(') {
						check = 0;
						break;
					}
				}
			}
			if (a.empty() && check) {
				cout << "yes" << '\n';
			}
			else {
				cout << "no" << '\n';
			}
		}
	}
	
}