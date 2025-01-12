
#include <iostream>
#include <string.h>
using namespace std;

int arr[101][11][11]; // 스티커 원본 배열
int c_arr[101][11][11]; // 회전 후 임시 배열
int n, m, k; // 노트북 크기 (n, m) 및 스티커 수 (k)
int ans[41][41]; // 노트북 상태 저장

void go(int s, int r, int c, int d) {
    if (d == 1) {
        // 원래 스티커 시도
        for (int i = 0; i <= n - r; i++) {
            for (int j = 0; j <= m - c; j++) {
                int check = 1;
                for (int h = i; h < i + r; h++) {
                    for (int b = j; b < j + c; b++) {
                        if (check == 0) break;
                        if (arr[s][h - i][b - j] == 1 && ans[h][b] == 1) {
                            check = 0;
                            break;
                        }
                    }
                }
                if (check == 1) {
                    for (int h = i; h < i + r; h++) {
                        for (int b = j; b < j + c; b++) {
                            if (arr[s][h - i][b - j] == 1) {
                                ans[h][b] = 1;
                            }
                        }
                    }
                    return;
                }
            }
        }
        go(s, c, r, d + 1);
    } else if (d == 2 || d == 3 || d == 4) {
        // 스티커 회전
        memset(c_arr, 0, sizeof(c_arr));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                c_arr[s][i][j] = arr[s][c - j - 1][i];
            }
        }
        memcpy(arr[s], c_arr[s], sizeof(c_arr[s]));

        for (int i = 0; i <= n - r; i++) {
            for (int j = 0; j <= m - c; j++) {
                int check = 1;
                for (int h = i; h < i + r; h++) {
                    for (int b = j; b < j + c; b++) {
                        if (check == 0) break;
                        if (arr[s][h - i][b - j] == 1 && ans[h][b] == 1) {
                            check = 0;
                            break;
                        }
                    }
                }
                if (check == 1) {
                    for (int h = i; h < i + r; h++) {
                        for (int b = j; b < j + c; b++) {
                            if (arr[s][h - i][b - j] == 1) {
                                ans[h][b] = 1;
                            }
                        }
                    }
                    return;
                }
            }
        }
        if (d == 4) return;
        go(s, c, r, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        for (int j = 0; j < r; j++) {
            for (int h = 0; h < c; h++) {
                cin >> arr[i][j][h];
            }
        }
        go(i, r, c, 1);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 1) {
                count++;
            }
        }
    }
    cout << count << '\n';

    return 0;
}
