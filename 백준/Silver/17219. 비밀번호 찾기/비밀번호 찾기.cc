#include <iostream>
#include <map>
using namespace std;
map<string, string>M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string passward;
	string address;
	for (int i = 0; i < n; i++) {
		cin >> address >> passward;
		M[address] = passward;
	}
	for (int i = 0; i < m; i++) {
		cin >> address;
		cout << M[address] << '\n';
	}

}