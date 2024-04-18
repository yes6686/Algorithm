#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		double d,va, vb,f;
		cin >> d>> va >> vb>>f;
		double ans = (d / (va + vb))*f;
		cout <<n<<" "<< ans << '\n';
	}
}