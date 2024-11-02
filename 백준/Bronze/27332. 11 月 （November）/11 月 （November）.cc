#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b; cin >> a >> b;
  int days = a + 7 * b;
  if (days >= 1 && days <= 30) cout << "1\n";
  else cout << "0\n";
}