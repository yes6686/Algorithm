#include <iostream>
#include <vector>
using namespace std;

vector<int>v1;
vector<int>v2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v1.insert(v1.begin()+(x-1), i);
    }
    while (v1.size() > m) {
        v1.pop_back();
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        v2.insert(v2.begin() + (x - 1), v1.back());
        v1.pop_back();

    }
    while (v2.size() > 3) {
        v2.pop_back();
    }
    vector<int>::iterator it;
    for (it = v2.begin(); it != v2.end(); it++) {
        cout << *it << '\n';
    }
}
