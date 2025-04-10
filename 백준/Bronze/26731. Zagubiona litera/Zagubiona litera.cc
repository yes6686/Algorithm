#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str; cin >> str;

  for (char c = 'A'; c <= 'Z'; c++) {
    if (str.find(c) == string::npos) {
      cout << c << "\n";
      break ;
    }
  }
}