#include <iostream>
using namespace std;

int darr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
string days[7] = { "Monday","Tuesday","Wednesday",
"Thursday","Friday","Saturday","Sunday" };

int main() {

	int d, m;
	cin >> d >> m;
	int dd = 1;
	int mm = 1;
	int day = 3;
	while (1) {
		if (dd == d && mm == m) {
			cout << days[day];
			break;
		}
		dd++;
		day++;
		if (day == 7) day = 0;
		if (darr[mm] < dd) {
			mm++;
			dd = 1;
		}
	}	
}