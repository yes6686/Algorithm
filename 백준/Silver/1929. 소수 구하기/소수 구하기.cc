#include <iostream>
using namespace std;
int arr[1000001];
int main() {
	
	int a, b;
	cin >> a >> b;
	
	
	for (int i = 2; i <= b; i++) {
		arr[i] = i;
	}
	for(int i=2;i*i<=b;i++){
		if (arr[i] == 0) continue;
		for (int j = 2 * i; j <= b; j += i) {
			if (arr[j] == 0) continue;
			else arr[j] = 0;
		}
	}
	for (int i = a; i <= b; i++) {
		if (arr[i] != 0) {
			printf("%d\n", arr[i]);
		}
	}

	
}