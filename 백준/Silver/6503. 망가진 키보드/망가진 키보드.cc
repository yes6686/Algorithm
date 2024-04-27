#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int arr[321];

int main() {
    
    
    
    
	
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		cin.ignore();
		string s;
		getline(cin, s);
		int a = 0, b = 0;
		int maxAns = 0;
		int cnt = 0;
		while (a<=b) {
			if (b >= s.size()) break;
			if (arr[s[b]]) {
				arr[s[b]]++;
				b++;
				maxAns = max(maxAns, b - a);
				continue;
			}

			if (cnt < n) {
				arr[s[b]]++;
				b++;
				maxAns = max(maxAns, b - a);
				cnt++;
			}
			else {
				arr[s[a]]--;
				if (arr[s[a]] == 0) {
					cnt--;
				}
				a++;
			}
		}
		memset(arr, 0, sizeof(arr));
		cout << maxAns << '\n';
	}
}