#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  if (n > m) swap(n, m);

  cout << min(n + m, n + n + 1) << "\n";

  return 0;
}