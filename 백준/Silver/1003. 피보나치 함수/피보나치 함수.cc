#include <iostream>
using namespace std;

int dp[41] = { 0,1 };

int main() {
    for (int i = 2; i < 41; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int T;
    cin >> T;
    int x;
    while (T--) {
        cin >> x;
        if (x == 0)  cout << 1 << ' ' << 0 << '\n';
        else if (x == 1)  cout << 0 << ' ' << 1 << '\n';
        else cout << dp[x - 1] << ' ' << dp[x] << '\n';
    }
}