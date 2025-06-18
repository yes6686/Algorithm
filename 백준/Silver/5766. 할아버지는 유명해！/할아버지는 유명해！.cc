#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

pair<int,int> arr[10001];

bool compare1(pair<int,int> a, pair<int, int> b) {
	return a.first > b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				int x;
				cin >> x;
				arr[x].first++;
				arr[x].second = x;
			}
		}

		sort(arr, arr + 10000, compare1);
		
		int secondV = arr[1].first;


		sort(arr, arr + 10000, compare2);

		for (int i = 1;i < 10001;i++) {

			if (arr[i].second == 0) continue;
			if(arr[i].first == secondV)
			cout << arr[i].second << ' ';
			
		}
		cout << '\n';
		memset(arr, 0, sizeof(arr));
	}
}

