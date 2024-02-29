#include <iostream>	
#include <algorithm>
using namespace std;

int arr[100];
int arr1[10];
int result[6];
int main() {

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		arr1[i] = arr[i];
	}
	sort(arr, arr + 8);
	int sum = 0;
	int k = 1;
	for (int i = 3; i < 8; i++) {
		sum += arr[i];
		for (int j = 0; j < 8; j++) {
			if (arr[i] == arr1[j]) {
				result[k] = j+1;
				k++;
				
			}
		}
	}
	cout << sum << endl;
	sort(result, result + 6);
	for (int i = 1; i <= 5; i++) {
		cout << result[i] << ' ';
	}
}