#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	int A[51];
	int B[51];
	int C[51];
	int max;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		B[i] = A[i];
		C[i] = A[i];

	}
	
	int index;
	for (int i = 0; i < n; i++) {
      max = 1001;
		for (int j = i; j< n; j++) {
			if (max > A[j]) {
				max = A[j];
				index = j;
			}
			
		}
		int tmp1 = A[i];
		A[i] = A[index];
		A[index] = tmp1;

		int tmp2 = B[i];
		B[i] = B[index];
		B[index] = tmp2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (C[i] == B[j]) {
				C[i] = j;
               B[j] = -1;	
                break;
		}
			
		}
		
	
	}
	for (int i = 0; i < n; i++) {
		cout << C[i] << ' ';
	
	}

	
}