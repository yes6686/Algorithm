#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int>q;

	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	while(!q.empty()) {
		for (int j = 1; j < k; j++) {
			int a = q.front();
			q.pop();
			q.push(a);
		}
		//int b = q.front();
		if (q.size() >= 2) {
			cout << q.front() << ", ";
			q.pop();
		}
		else {
			break;
		}
		
	}
	
	cout <<q.front()<< ">";
}