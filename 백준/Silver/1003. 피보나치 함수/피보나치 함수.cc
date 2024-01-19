#include <iostream>
using namespace std;

long long int zeroCntDp[41];
long long int oneCntDp[41];

long long int zeroCntFibo(int n) {
    if (zeroCntDp[n] != -1) return zeroCntDp[n];
    if (n == 0) {
        zeroCntDp[n] = 1;
        return zeroCntDp[n];
    }
    else if (n == 1) {
        zeroCntDp[n] = 0;
        return zeroCntDp[n];
    }
    else {
        return  zeroCntDp[n] = zeroCntFibo(n-1) + zeroCntFibo(n-2);
    }
}

long long int oneCntFibo(int n) {
    if (oneCntDp[n] != -1) return oneCntDp[n];
    if (n == 0) {
        oneCntDp[n] = 0;
        return oneCntDp[n];
    }
    else if (n == 1) {
        oneCntDp[n] = 1;
        return oneCntDp[n];
    }
    else {
        return  oneCntDp[n] = oneCntFibo(n - 1) + oneCntFibo(n - 2);
    }
}

int main() {

    for (int i = 0; i < 41; i++) {
        zeroCntDp[i] = -1;
        oneCntDp[i] = -1;
    }
    int T;
    cin >> T;
    int x;
    while (T--) {
        cin >> x;
        cout << zeroCntFibo(x) << ' ' << oneCntFibo(x) << '\n';
    }
}