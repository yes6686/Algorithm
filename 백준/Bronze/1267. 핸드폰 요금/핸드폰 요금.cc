#include <iostream>
using namespace std;

int arr[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int s1 = 0;
	int s2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		s1 += ((arr[i] / 30)+1) * 10;
		s2 += ((arr[i] / 60)+1) * 15;
	}
	if (s1 > s2) {
		cout << "M "<<s2<<'\n';
	}
	else if (s1 < s2) {
		cout << "Y "<<s1<<'\n';
	}
	else {
		cout << "Y M " << s1 << '\n';
	}
}