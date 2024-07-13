#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visited[6];
string str;
vector<string>v;

void dfs(string s , int d) {
    if (d == str.size()) {
        v.push_back(s);
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs(s + str[i], d + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str;
    dfs("", 0);
    sort(v.begin(), v.end());
    vector<string>::iterator it;

    for (it = v.begin()+1; it != v.end(); it++) {
        if (*it != str && *(it-1) == str) {
            cout << *it << '\n';
            return 0;
        }
    }
    cout << 0;
}