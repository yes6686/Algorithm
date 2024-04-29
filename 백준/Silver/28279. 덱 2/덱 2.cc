#include<iostream>
#include<deque>

using namespace std;

deque<int> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cmd, x;
	cin >> n;
	while (n--){
		cin >> cmd;
		switch (cmd){
		case 1:
			cin >> x;
			dq.push_front(x);
			break;
		case 2:
			cin >> x;
			dq.push_back(x);
			break;
		case 3:
			if (dq.empty()){
				cout << -1 << "\n";
			}else{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			break;
		case 4:
			if (dq.empty()){
				cout << -1 << "\n";
			}else{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			break;
		case 5:
			cout << dq.size() << "\n";
			break;
		case 6:
			(dq.empty()) ? cout << 1 << "\n" : cout << 0 << "\n";
			break;
		case 7:
			if (dq.empty()){
				cout << -1 << "\n";
			}
			else{
				cout << dq.front() << "\n";
			}
			break;
		case 8:
			if (dq.empty()){
				cout << -1 << "\n";
			}
			else{
				cout << dq.back() << "\n";
			}
			break;}}}