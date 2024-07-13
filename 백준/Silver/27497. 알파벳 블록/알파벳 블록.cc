#include <iostream>
#include <deque>
using namespace std;

deque<pair<char,int>>dq;

int ch[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        char c;
        cin >> x;
        if (x == 1) {
            cin >> c;
            cnt++;
            dq.push_back({ c,cnt });
        }
        else if (x == 2) {
            cin >> c;
            cnt++;
            dq.push_front({ c,cnt });
        }
        else {
            if (dq.size()) {
                if (dq.front().second < dq.back().second) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }
    }
    if (dq.empty()) {
        cout << 0;
    }
    while (!dq.empty()) {
        cout << dq.front().first;
        dq.pop_front();
    }
}