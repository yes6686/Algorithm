#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    string str;
    cin >> str;
    cout << str.size() + count(str.begin(), str.end(), ':') + count(str.begin(), str.end(), '_') * 5;
	return 0;
}