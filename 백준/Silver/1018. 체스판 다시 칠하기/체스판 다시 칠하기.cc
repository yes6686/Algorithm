#include <iostream>
using namespace std;
char c[51][51];
char arrw[8][8] = { {'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'}
};
char arrb[8][8] = { 
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'}
};


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}

	int min = 2500;
	int cntw = 0;
	int cntb = 0;
	int a = 0;
	int b = 0;
	for (int i = 0; i < n - 8 + 1; i++) {
		for (int j = 0; j < m - 8 + 1; j++) {
			for (int t = i; t < i + 8; t++) {
				for (int h = j; h < j + 8; h++) {
					if (c[t][h] != arrw[a][b]) {
						cntw++;

					}
					if (c[t][h] != arrb[a][b]) {
						cntb++;
					}
					b++;
				}
				a++;
				b = 0;
			}
			if (cntw < cntb) {
				if (min > cntw) {
					min = cntw;
				}
			}
			else {
				if (min > cntb) {
					min = cntb;
                    }
				}
			cntw = 0;
			cntb = 0;
			a = 0;
			b = 0;
		}
	}
	cout << min << endl;
}