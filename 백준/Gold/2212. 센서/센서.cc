#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n <= k) {
        cout << 0 << '\n';
        return 0;
    }

    sort(arr, arr + n);

    vector<int> gaps;
    for (int i = 0; i < n - 1; i++) {
        gaps.push_back(arr[i + 1] - arr[i]);
    }

    sort(gaps.rbegin(), gaps.rend());
    
    int ans = 0;
    for (int i = k - 1; i < gaps.size(); i++) {
        ans += gaps[i];
    }

    cout << ans << '\n';
}