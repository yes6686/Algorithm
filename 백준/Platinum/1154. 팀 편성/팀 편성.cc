#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[1001];

int checkA[1001];
int checkB[1001];
int ch[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    checkA[1] = 1;
    int count = 2;
    while (count--) {
        for (int i = 1; i <= n; i++) {

            for (int j = 0; j < v[i].size(); j++) {
                int k = v[i][j];

                ch[k] = 1;
            }
            ch[i] = 1;
            if (checkA[i] == 1) {
                for (int j = 1; j <= n; j++) {
                    if (ch[j] == 0) {

                        if (checkA[j] == 1) {
                            cout << -1 << '\n';
                            return 0;
                        }
                        checkB[j] = 1;
                    }
                }

            }
            else if (checkB[i] == 1) {
                for (int j = 1; j <= n; j++) {
                    if (ch[j] == 0) {

                        if (checkB[j] == 1) {
                            cout << -1 << '\n';
                            return 0;
                        }
                        checkA[j] = 1;
                    }
                }
            }
            else {

                int chA = 0;
                int chB = 0;

                for (int j = 1; j <= n; j++) {
                    if (ch[j] == 0) {

                        if (checkB[j] == 1) {
                            if (chA == 1) {
                                cout << -1 << '\n';
                                return 0;
                            }
                            chB = 1;
                        }
                        else if (checkA[j] == 1) {
                            if (chB == 1) {
                                cout << -1 << '\n';
                                return 0;
                            }
                            chA = 1;

                        }
                    }
                }
                if (chB == 1) {
                    checkA[i] = 1;
                }
                else if (chA == 1) {
                    checkB[i] = 1;
                }

                if (count == 0) {
                    if (chB == 0 && chA == 0) {
                        checkA[i] = 1;
                    }
                }
                for (int j = 1; j <= n; j++) {
                    if (ch[j] == 1) continue;
                    if (chB == 1) {
                        checkB[j] = 1;
                    }
                    else if (chA == 1) {
                        checkA[j] = 1;
                    }
                }

            }
            memset(ch, 0, sizeof(ch));

        }
    }
    cout << 1 << '\n';
    for (int i = 1; i <= n; i++) {
        if (checkA[i] == 1) {
            cout << i << " ";
        }
    }

    cout << -1 << '\n';
    for (int i = 1; i <= n; i++) {
        if (checkB[i] == 1) {
            cout << i << " ";
        }
    }
    cout << -1 << '\n';
}