#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if ('Z' - s[i] < k && s[i]!='A') {
            k -= (('Z' - s[i]) + 1);
            s[i] = 'A';
        }
        if (i == s.size() - 1) {
            k %= 26;
            int kk = (int)s[i] + k;
            if (kk > 90) {
                kk %= 90;
                kk += 64;
            }
            s[i] = (char)kk;
        }
    }
    cout << s;
}