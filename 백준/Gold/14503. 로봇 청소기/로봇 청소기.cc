#include <iostream>
using namespace std;
int arr[51][51];
int main() {

	int n, m;

	cin >> n >> m;
	int initX, initY;
	int angle;
	cin >> initX >> initY >> angle;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	while (1) {
		if (arr[initX][initY] == 0) {
			cnt++;
			arr[initX][initY] = 2;
		}
		if (arr[initX + 1][initY] != 0 && arr[initX][initY + 1] != 0
			&& arr[initX - 1][initY] != 0 && arr[initX][initY - 1] != 0) {
			if (angle == 0 && arr[initX+1][initY] != 1) {
				initX++;
			}
			else if (angle == 1 && arr[initX][initY - 1] != 1) {
				initY--;
			}
			else if (angle == 2 && arr[initX-1][initY] != 1) {
				initX--;
			}
			else if (angle == 3 && arr[initX][initY+1] != 1) {
				initY++;
			}
			else { break; }
		}
		else {
			angle--;
			if (angle < 0) {
				angle = 3;
			}
			if (angle == 0 && arr[initX-1][initY] == 0) {
				
				initX--;
			}
			else if (angle == 1 && arr[initX][initY+1] == 0) {
			
				initY++;
			}
			else if (angle == 2 && arr[initX+1][initY] == 0) {
				
				initX++;
			}
			else if (angle == 3 && arr[initX][initY-1] == 0) {
			
				initY--;
			}
		}
	}
	cout << cnt;


}
