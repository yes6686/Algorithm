#include <iostream>

using namespace std;
int main() {
	int x=0, y=0;
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt == n) {
			break;
		}
		for (int j = 1; j <= i; j++) {
			cnt++;
			int x = j; 
			int y = i + 1 - j;
		
			
			if (cnt == n) {
				if (i % 2 == 0) {
					printf("%d/%d", x, y);
					
				}
			else {
					printf("%d/%d", y, x);
					

			}
				break;
			}
		}

	}
	
}