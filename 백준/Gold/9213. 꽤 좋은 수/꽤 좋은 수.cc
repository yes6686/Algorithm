#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s,e,badness;
	int cnt = 1;
	for (int i = 1; i < 1000000; i++) {
		for (int j = i * 2; j < 1000000; j += i) {
			arr[j] += i;
		}
	}
	while (1) {
		cin >> s >> e >> badness;
		if (s == 0 && e == 0 && badness == 0) break;
		int ans = 0;
		for (int i = s; i <= e; i++) {
			if (badness >= abs(arr[i]-i)) ans++;	
		}
		cout <<"Test "<<cnt<<": " << ans << '\n';
		cnt++;
	}
}