#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  string input; cin >> input;

  if (input[n - 1] == 'G') input.erase(n - 1, 1);
  else input.push_back('G');

  cout << input << "\n";
}
