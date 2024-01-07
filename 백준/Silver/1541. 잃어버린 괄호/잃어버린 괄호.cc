#include <iostream>
#include <math.h>
using namespace std;


int main() {

	string n;
	cin >> n;
	int sum=0;
	int cnt = 0;
	int yaechan = 1;
	for (int i = 0; i <= n.size(); i++) {
		if (n[i] == '-' || n[i]=='+'|| i==n.size()) {
			
			for (int j = cnt; j < i; j++) {
				sum += (n[j] - '0')*int(pow(10,i-j-1))*yaechan;
			}
			if (n[i] == '-') yaechan = -1;
			cnt = i+1;
			

		}
	}
	cout << sum;

}