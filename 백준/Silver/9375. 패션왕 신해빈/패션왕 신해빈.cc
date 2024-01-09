#include <iostream>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int n;
	cin >> T;
	string a, b;
	int result = 1;
	while (T--) {
		result = 1;
		map<string, int>m;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			if (m.find(b) == m.end()) {
				m.insert({ b,1 });
			}
			else {
				m[b] += 1;
			}
		}
		for (auto iter : m) {
			result *= (iter.second + 1);
		}
		result -= 1;
		cout << result << '\n';
			
	}
	
		
}

	
