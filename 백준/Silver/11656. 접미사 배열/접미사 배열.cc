#include <iostream>
#include <algorithm>
using namespace std;

string str[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        str[i] = s;
        for (int j = 0; j < s.size()-1; j++) {
            s[j] = s[j + 1];
        }
        s.pop_back();
    }
    sort(str, str + size);
    for (int i = 0; i < size; i++) {
        cout << str[i] << '\n';
    }
}
