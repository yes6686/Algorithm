#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double L;
    cin >> L;
    cout << fixed;
    cout.precision(15);
    cout << (sqrt(3) * pow(L, 2)) / 4;
}