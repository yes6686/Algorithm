#include <iostream>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int maxAns = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i]) {
            dp[i] = dp[i - 1] + 1;
        }
        else if(arr[i-1]==arr[i]) {
            if (dp[i - 1] < arr[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        else {
            if (dp[i - 1] < arr[i]) {
                dp[i] = dp[i - 1] + 1;
            }
            else if (dp[i - 1] == arr[i]) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = arr[i];
            }
        }
        maxAns = max(maxAns, dp[i]);
    }
    cout << maxAns;

}
