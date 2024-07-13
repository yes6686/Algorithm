#include <iostream>
using namespace std;

char arr[51][51];

string str[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            arr[i][j] = s[j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int t = 0; t < zc; t++) {
                str[i] += arr[i][j];
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < zr; j++) {
            cout << str[i] << endl;
        }
    }
}