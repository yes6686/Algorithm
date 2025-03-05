#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, k, a, b; cin >> n >> k >> a >> b;

  int elevTime = abs(1 - k) * b + (n - 1) * b;
  int stairTime = (n - 1) * a;

  cout << elevTime << " " << stairTime << "\n";
}