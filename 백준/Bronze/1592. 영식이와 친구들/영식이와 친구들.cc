#include <iostream>
using namespace std;

int arr[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l;
    cin >> n >> m >> l;
    int i = 1;
    int cnt = -1;
    while (true) {
        arr[i]++;
        cnt++;
        if (arr[i] >= m) {
            break;
        }
        if (arr[i] % 2 == 0) {
            i -= l;
            if (i <= 0) {
                i += n;
            }
        }
        else {
            if (i + l > n) {
                i = (i + l) % n;
            }
            else {
                i += l;
            }
        }
    }
    cout << cnt;
}
