#include <iostream>
#include <string>
using namespace std;


int main() {
	string a;
	long long int result = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a;
		if (a == "black") {
			if (i == 0) result = 0;
			else if (i == 1)result += 0;
			else if (i == 2) result *= 1;
		
		}
		else if (a == "brown") {
			if (i == 0) result = 10;
			else if (i == 1)result += 1;
			else if (i == 2) result *= 10;

		}
		else if (a == "red") {
			if (i == 0) result = 20;
			else if (i == 1)result += 2;
			else if (i == 2) result *= 100;

		}
		else if (a == "orange") {
			if (i == 0) result = 30;
			else if (i == 1)result += 3;
			else if (i == 2) result *= 1000;

		}
		else if (a == "yellow") {
			if (i == 0) result = 40;
			else if (i == 1)result += 4;
			else if (i == 2) result *= 10000;

		}
		else if (a == "green") {
			if (i == 0) result = 50;
			else if (i == 1)result += 5;
			else if (i == 2) result *= 100000;

		}
		else if (a == "blue") {
			if (i == 0) result = 60;
			else if (i == 1)result += 6;
			else if (i == 2) result *= 1000000;

		}
		else if (a == "violet") {
			if (i == 0) result = 70;
			else if (i == 1)result += 7;
			else if (i == 2) result *= 10000000;

		}
		else if (a == "grey") {
			if (i == 0) result = 80;
			else if (i == 1)result += 8;
			else if (i == 2) result *= 100000000;

		}
		else if (a == "white") {
			if (i == 0) result = 90;
			else if (i == 1)result += 9;
			else if (i == 2) result *= 1000000000;

		}
		else {
			cout << "f";
		}
	}
	cout << result;
	
}