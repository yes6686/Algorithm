#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sh, sm, ss, eh, em, es;

    int s, e, ti, ho, min, sec;
    for (int i = 0; i < 3; i++) {

        cin >> sh >> sm >> ss >> eh >> em >> es;
        s = (sh * 3600) + (sm * 60) + ss;
        e = (eh * 3600) + (em * 60) + es;
        ti = e - s;
        ho = ti / 3600;

        min = (ti % 3600) / 60;

        sec = (ti % 3600) % 60;

        cout << ho << " " << min << " " << sec << '\n';
    }
}