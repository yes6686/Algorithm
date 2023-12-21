#include <iostream>
using namespace std;

int main() {
	
	int N;
	cin >> N;
	int cnt = 0;
	while (1) {
		if (N % 5 != 0) {
			N -= 3;
			cnt++;
			if (N == 0) {
				break;
			}
			else if (N < 0) {
				cnt = -1;
				break;
			}
		}
		else {
			cnt += (N / 5);
			break;
		}
	}
	cout << cnt;
}