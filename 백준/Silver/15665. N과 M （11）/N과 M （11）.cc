#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int arr[8];
int visited[8];
int n, m;
map<string, int>mp;

void bt(int d,string s) {
	
	if (d >= m) {
		if (mp[s] == 0) {
			mp[s] = 1;
			cout << s << '\n';
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		bt(d + 1, s + to_string(arr[i])+" ");
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	bt(0,"");
}