#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char n[501];
	while (cin.getline(n,501)) {
		if (strcmp("END", n)==0) {
			break;
		}
		int len = strlen(n);
		for (int i = 0; i <	len / 2; i++) {
			char temp = n[i];
			n[i] = n[len - i - 1];
			n[len - i - 1] = temp;
		}
		cout << n << endl;
	}
}