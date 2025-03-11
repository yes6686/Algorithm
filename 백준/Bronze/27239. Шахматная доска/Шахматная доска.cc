#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  int row = (n - 1) / 8,
      col = (n - 1) % 8;

  char c = 'a' + col;

  cout << c << row + 1 << "\n";
}