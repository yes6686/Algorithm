#include<iostream>
using namespace std;

int main() {
	int g, p, t;
	cin >> g >> p >> t;
	int group = g + p * t;
	int one = g*p;
	if (one < group)
		cout << 1;
	else if (one > group)
		cout << 2;
	else
		cout << 0;
}