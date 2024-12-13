#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int h, w;
		cin >> h >> w;
		if (h == 0 && w == 0) break;

		int curDiagonal = h * h + w * w;
		int maxDiagonal = 20001;


		int nh=h, nw=w;
		for (int i = 1; i < 150; i++) {
			for (int j = i+1; j <= 150; j++) {
				int diagonal = i * i + j * j;
				if (diagonal == curDiagonal ) {
					if (h < i ) {
						if (maxDiagonal != curDiagonal) {
							maxDiagonal = diagonal;
							nh = i;
							nw = j;
						}
						else {
							if (nh > i) {
								nh = i;
								nw = j;
							}
						}
						
					}
				}
				else if (diagonal > curDiagonal && diagonal <= maxDiagonal) {
					if (diagonal == maxDiagonal) {
						if (nh > i) {
							nh = i;
							nw = j;
						}
					}
					else {
						maxDiagonal = diagonal;
						nh = i;
						nw = j;
					}
				}
			}
		}
		cout << nh << ' ' << nw << '\n';
	}
}