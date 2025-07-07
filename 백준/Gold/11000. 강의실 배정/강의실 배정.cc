#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int,int> arr[200001];

priority_queue<int,vector<int>,greater<int> >pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + n);

	pq.push(arr[0].second);

	int ans = 1;
	for (int i = 1;i < n;i++) {
		if (pq.top() <= arr[i].first) {
			pq.pop();
			pq.push(arr[i].second);
		}
		else{
			ans++;
			pq.push(arr[i].second);
		}
	}
	
	cout << ans << '\n';
}