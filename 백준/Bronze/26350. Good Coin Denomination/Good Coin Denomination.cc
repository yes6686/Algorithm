#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    int d; cin >> d;
    vector<int> coins(d);

    for (int j = 0; j < d; j++)
      cin >> coins[j];

    cout << "Denominations: ";
    for (int j = 0; j < d; j++)
      cout << coins[j] << " ";
    cout << "\n";

    bool isValid = true;
    int prev = coins[0];
    for (int j = 1; j < d; j++) {
      if (coins[j] < 2 * prev) {
        isValid = false;
        break;
      }
      prev = coins[j];
    }

    if (isValid) cout << "Good coin denominations!\n";
    else cout << "Bad coin denominations!\n";
    if (i != n - 1) cout << "\n";
  }
}
