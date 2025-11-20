#include <iostream>
#include <string.h>
using namespace std;

int arrA[51];
int arrB[51];
int ch[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	while (T--) {
		int b, w, x, y, z;
		cin >> b >> w >> x >> y >> z;
		int maxAns = b*x + w*y;


		if (b > w) {
			maxAns = max(maxAns, w * z + w * z + (b - w) * x);
		}
		else {
			maxAns = max(maxAns, b * z + b * z + (w - b) * y);
		}

		cout << maxAns << '\n';
		
	}

}