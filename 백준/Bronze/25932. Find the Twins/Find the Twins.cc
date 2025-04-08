#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    vector<int> uniformNums(10);
    for (int j = 0; j < 10; j++)
      cin >> uniformNums[j];

    bool isZackFound = false, isMackFound = false;
    for (int j = 0; j < 10; j++) {
      cout << uniformNums[j] << " ";
      if (uniformNums[j] == 17) isZackFound = true;
      if (uniformNums[j] == 18) isMackFound = true;
    }
    cout << "\n";

    if (isZackFound && isMackFound) cout << "both\n";
    else if (isZackFound) cout << "zack\n";
    else if (isMackFound) cout << "mack\n";
    else cout << "none\n";

    if (i != n - 1) cout << "\n";
  }
}