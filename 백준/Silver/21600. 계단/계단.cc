
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1; // 첫 번째 계단의 길이는 1
    int maxLength = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > dp[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        else {
            dp[i] = arr[i];
        }
        maxLength = max(maxLength, dp[i]);
    }

    cout << maxLength << '\n';

    return 0;
}
