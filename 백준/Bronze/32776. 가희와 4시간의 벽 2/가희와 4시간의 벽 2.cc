#include <iostream>
using namespace std;

int main() {
    int S_ab, M_a, F_ab, M_b;
    cin >> S_ab >> M_a >> F_ab >> M_b;

    int flight_time = M_a + F_ab + M_b;

    if (S_ab <= flight_time || S_ab <= 240) {
        cout << "high speed rail" << '\n';
    } else {
        cout << "flight" << '\n';
    }

    return 0;
}
  