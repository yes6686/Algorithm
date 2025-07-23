#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];

vector<int>v0;
vector<int>v1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		if (x == 0) {
			v0.push_back(x);
		}
		else {
			v1.push_back(x);
		}
	}

	long long int ans = 0;

	if (v1.size() == 1) {
		if (v0.size() >= 3) {
			long long int v0Size = v0.size();
			if (v0Size >= 3) ans += ((v0Size) * (v0Size - 1) * (v0Size - 2)) / 6;
			cout << ans << '\n';
		}
		else {
			cout << 0 << '\n';
		}
		return 0;
	}
	else if(v1.size()==2){
		if ((v1[0] + v1[1]) == 0) {
			ans += v0.size();
		}

		long long int v0Size = v0.size();
		if (v0Size >= 3) ans += ((v0Size) * (v0Size - 1) * (v0Size - 2)) / 6;
		cout << ans << '\n';

		return 0;
	}

	sort(v1.begin(), v1.end());

	int v1Size = v1.size();
	for (int i = 0;i < v1Size - 1;i++) {
		for (int j = i + 1;j < v1Size;j++) {
			int k = v1[i] + v1[j];
			if (k > 0) continue;
			if (k == 0) {
				ans += v0.size();
				continue;
			}
			int kx = k * (-1);
			vector<int>::iterator s = lower_bound(v1.begin() + (j + 1), v1.end(), kx);
			vector<int>::iterator e = upper_bound(v1.begin() + (j + 1), v1.end(), kx);
			ans += (e - s);
		}
	}

	long long int v0Size = v0.size();
	if(v0Size>=3) ans += ((v0Size) * (v0Size - 1) * (v0Size - 2)) / 6;
	cout << ans;

}