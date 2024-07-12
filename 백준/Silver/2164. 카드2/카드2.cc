#include <iostream>
#include <queue>
using namespace std;
queue<int>q;
int main() {

	int n;
	cin >> n;
	for (int i = 1; i <=n; i++) {
		q.push(i);
	}
	int k;
	while (1) {
		if (q.size() == 1) {
			cout << q.front() << endl;
			break;
		}
        q.pop();
		k = q.front();
		q.pop();
		q.push(k);
		
	}

}