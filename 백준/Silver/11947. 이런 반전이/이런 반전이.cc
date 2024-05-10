// 3번
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {

		string n;
		cin >> n;
		if (n == "1000000000") {
			cout << "8999999999000000000" << '\n';
			continue;
		}
		string k = "5";
		
		for (int i = 0; i < n.size() - 1; i++) {
			k += '0';
		}
		long long int nn = stol(n);
		long long int kk = stol(k);
		if (nn < kk) {
			long long int ss = 0;
			for (int i = 0; i < n.size(); i++) {
				ss *= 10;
				ss += 9 - (int)(n[i] - '0');
			}
			cout << nn * ss << '\n';
		}
		else {
			long long int ss = 0;
			for (int i = 0; i < k.size(); i++) {
				ss *= 10;
				ss += 9 - (int)(k[i] - '0');
			}
			cout << kk * ss << '\n';
		}
	}
}