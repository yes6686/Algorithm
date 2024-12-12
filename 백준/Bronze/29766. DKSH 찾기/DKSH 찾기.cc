#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, a = "DKSH";
  int cnt = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    int flag = 0;
    for (int j = 0; j < 4; j++) {
      if (s[i + j] != a[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag)
      cnt++;
  }
  cout << cnt;
  return 0;
}