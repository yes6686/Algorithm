#include <iostream>
using namespace std;

int arr[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int c = i * i + j * j + m;
                int p = i * j;
                if (c % p == 0 ) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}
