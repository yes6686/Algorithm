#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int y1, m1, d1, y2, m2, d2;
    int year1, year2, year3;
    
    cin >> y1 >> m1 >> d1;
    
    cin >> y2 >> m2 >> d2;

    if (m1 < m2)
        year1 = y2 - y1;
    else if (m1 == m2 && d1 <= d2)
        year1 = y2 - y1;
    else
        year1 = y2 - y1 - 1;

    year2 = y2 - y1 + 1;
    year3 = y2 - y1;

    cout << year1 << "\n" << year2 << "\n" << year3;
}