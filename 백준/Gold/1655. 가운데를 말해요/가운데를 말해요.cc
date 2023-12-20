#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int>>q1;
priority_queue<int, vector<int>, greater<int>>q2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int x;
	int mid;
	int Rcnt = 0;
	int Lcnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (i == 1) {
			cout <<x << '\n';
			mid = x;
		}
		else {
			if (mid < x) {
				q2.push(x);
				Rcnt++;
				if (Rcnt > Lcnt + 1) {
					q1.push(mid);
					mid = q2.top();
					q2.pop();
					Rcnt--;
					Lcnt++;
				}
				cout << mid << '\n';
			}
			else {
				q1.push(x);
				Lcnt++;
				if (Lcnt > Rcnt) {
					q2.push(mid);
					mid = q1.top();
					q1.pop(); 
					Lcnt--;
					Rcnt++;
				}
				cout << mid << '\n';
			}

		}

	}
	

}
