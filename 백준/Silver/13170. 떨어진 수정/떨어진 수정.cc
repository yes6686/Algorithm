#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, K, W;
    double P;
    cin >> N >> K >> P >> W;
    int cnt = ceil(P / W);
    cout << cnt << '\n';
}