#include <iostream>
#include <string.h>

using namespace std;


void reverse(char a[]) {
	int len = strlen(a);
	for (int i = 0; i < len/2; i++) {
		char temp = a[i];
		a[i] = a[len - i - 1];
		a[len - i - 1] = temp;

	}
}
char a[10002];
char b[10002];
char result[10002];
int main() {
	int len;
	
	int carry=0;
	cin >> a >> b;
	reverse(a);
	reverse(b);
	if (strlen(a) > strlen(b)) {
		len = strlen(a);
	}
	else {
		len = strlen(b);
	}
	for (int i = 0; i < len; i++) {
		int sum = a[i] - '0' + b[i] - '0' + carry;
		if (sum < 0) {
			sum += '0';
		}
		
		if (sum >= 10) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		result[i] = sum%10+'0';
	}
	if(carry==1){
		result[len] = '1';
	}
	reverse(result);
	printf("%s", result);


}