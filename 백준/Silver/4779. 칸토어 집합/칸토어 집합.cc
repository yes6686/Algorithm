#include <iostream>
using namespace std;

string dp[13];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = "-";
    for (int i = 1; i <= 12; i++) {
        dp[i] += dp[i - 1];
        for (int j = 0; j < dp[i - 1].size(); j++) {
            dp[i] += " ";
        }
        dp[i] += dp[i - 1];
    }

    int n;
    while (cin>>n) {
        cout << dp[n] << '\n';
    }
}