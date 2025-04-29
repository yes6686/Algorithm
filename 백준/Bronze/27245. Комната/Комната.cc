#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, l, h; cin >> w >> l >> h;

  int minDim = min(w, l),
      maxDim = max(w, l);

  if ((minDim >= 2 * h) && (maxDim <= 2 * minDim))
    cout << "good" << "\n";
  else
    cout << "bad" << "\n";
}