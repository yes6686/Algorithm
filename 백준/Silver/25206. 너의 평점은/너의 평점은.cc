#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string st; 
	double avg = 0; 
	double sum = 0;
	string input;
	for (int i = 0; i < 20; i++)
	{
		float g;
		double s;
		cin >> st >> g >> input;
		if (input == "A+") s = 4.5;
		else if (input == "A0") s = 4.0;
		else if (input == "B+") s = 3.5;
		else if (input == "B0") s = 3.0;
		else if (input == "C+") s = 2.5;
		else if (input == "C0") s = 2.0;
		else if (input == "D+") s = 1.5;
		else if (input == "D0") s = 1.0;
		else if (input == "F") s = 0.0;
		else if (input == "P") { s = 0.0; g = 0; }
		avg += s * g;
		sum += g;
	}
    
	avg = avg / sum;
	cout << fixed;
	cout.precision(6);
	cout << avg;
}