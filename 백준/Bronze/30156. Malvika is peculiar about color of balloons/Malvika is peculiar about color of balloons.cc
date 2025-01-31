#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void solve(void) {
  string s; cin >> s;

  cout << min(count(s.begin(), s.end(), 'a'), count(s.begin(), s.end(), 'b')) << "\n";
}

int main(void) {
  int t; cin >> t;
  while (t--) solve();
}