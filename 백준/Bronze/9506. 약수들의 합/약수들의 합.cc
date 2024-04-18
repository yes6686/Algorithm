#include <iostream>
#include <queue>
using namespace std;
queue<int>q;
int main() {
	int n;
	int sum = 0;
	while (cin>>n) {
	
		if (n == -1) {
			break;
		}
		else {
			for (int i = 1; i < n; i++) {
				if (n % i == 0) {
					sum += i;
					q.push(i);
					
				}
			}
			if (sum == n) {
				cout << n << " = ";
				while (q.size() != 1) {
					int k = q.front();
					q.pop();
					cout << k << " + ";
				}
				cout << q.front() << endl;;
				q.pop();
			}
			else {
				cout << n << " is NOT perfect." << endl;
				while (!q.empty()) {
					q.pop();
				}
				
			}
			sum = 0;
		}
	}
}
