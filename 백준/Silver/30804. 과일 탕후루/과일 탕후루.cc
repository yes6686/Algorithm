#include <iostream>
using namespace std;

int arr[200001];
int num[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n <= 2) {
        cout << n << '\n';
        return 0;
    }

    int s = 0;
    int e = 2;
    int m = e - 1;
    int maxCnt = 2;
    int n1 = arr[0];
    int n2 = arr[1];

    while (e < n) {
        if (n1!=arr[e] && n2!=arr[e]) {
            maxCnt = max(maxCnt, e - s);
            m = e - 1;
            n2 = arr[e];
            n1 = arr[m];
            while (s <= m) {
                if (arr[m] == arr[m - 1]){
                    m--;
                }
                else {
                    break;
                }
            }
            s = m;
        }
        else {
            e++;
            maxCnt = max(maxCnt, e - s);
        }
    }
    cout << maxCnt << '\n';
}
