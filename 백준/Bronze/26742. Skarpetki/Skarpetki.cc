#include <bits/stdc++.h>
using namespace std;
int main() {

  string input; cin >> input;

  int whiteSocks = 0, blackSocks = 0;

  for (char c : input) {
    if (c == 'B') whiteSocks++;
    else blackSocks++;
  }

  int pairs = whiteSocks / 2 + blackSocks / 2;
  cout << pairs << "\n";
}