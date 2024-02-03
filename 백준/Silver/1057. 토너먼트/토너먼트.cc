#include <iostream>
using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int cnt = 1;
	while(1)
	{
		
		if ((a + 1) / 2 == (b + 1) / 2) {
			cout << cnt;
			break;
		}
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		cnt++;
	}
}