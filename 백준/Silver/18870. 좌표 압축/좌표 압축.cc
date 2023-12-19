#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int arr[1000001];
int c_arr[1000001];

map<string,int>mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		c_arr[i] = arr[i];
	}
	sort(c_arr, c_arr + n);
	int seq = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			mp[to_string(c_arr[i])] = seq;
			seq++;
		}
		else if (c_arr[i]!=c_arr[i-1]) {
			mp[to_string(c_arr[i])] = seq;
			seq++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << mp[to_string(arr[i])] << ' ';
	}

}

