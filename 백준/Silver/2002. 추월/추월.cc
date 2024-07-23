#include <iostream>
#include <map>
using namespace std;

int arr[1001];
map<string, int>mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n; 
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		arr[i] = mp[s];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int check = 0;
		for (int j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) {
				check = 1;
				break;
			}
		}
		if (check == 1) {
			ans++;
		}
	}
	cout << ans;
}