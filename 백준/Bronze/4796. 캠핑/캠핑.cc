#include <iostream>
using namespace std;


int main() {

	int L, P, V;
	int num = 1;
	while (1) {
		cin >> L >> P >> V;




		if (!L && !P && !V) {
			break;
		}
		else {
			if (P >= L) {
				if ((V % P) < L) {
					cout << "Case " << num << ": " << ((V / P) * L) + ((V % P)) % L << '\n';
				}
				else {
					cout << "Case " << num << ": " << ((V / P) * L) + L << '\n';

				}

			}
			else
				cout << "Case " << num << ": " << ((V / P) *P ) + (V % P)%L << '\n';

		}
		num++;
	}
}