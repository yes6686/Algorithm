#include <iostream>
using namespace std;
int arr[18][18];
int n;
int cnt = 0;
void DFS(int a,int b,int d) {
	if (a > n || b > n) {
		return;
	}
	if (arr[a][b] == 1) {
		return;
	}
	if (d == 2) {
		if (arr[a - 1][b] == 1 || arr[a][b - 1] == 1) {
			return;
		}
	}
	if (a == n && b == n) {
		cnt++;
		return;
	}
	if (b == n - 1 && a == n) {
		DFS(a, b + 1, 1);
	}
	else if (a == n - 1 && b == n) {
		DFS(a + 1, b, 3);
	}
	else if (b == n - 1 && a == n - 1) {
		DFS(a + 1, b + 1, 2);
	}
	else if (b == n - 1 && d==1) {
		DFS(a + 1, b + 1, 2);
	}
	else if (b == n-1 && d == 2) {
		DFS(a + 1, b+1, 2);
		DFS(a + 1, b, 3);
	}
	else if (b == n && d == 2) {
		DFS(a + 1, b, 3);
	}
	else if (b == n && d == 3) {
		DFS(a + 1, b, 3);
	}
	else if (a == n - 1 && d == 3) {
		DFS(a + 1, b + 1, 2);
	}
	else if (a == n-1 && d == 2) {
		DFS(a + 1, b+1, 2);
		DFS(a, b+1, 1);
	}
	else if (a == n && d == 2) {
		DFS(a, b + 1, 1);
	}
	else if (a == n && d == 1) {
		DFS(a, b + 1, 1);
	}
	else {
	if (d == 1) {
		DFS(a, b + 1, 1);
		DFS(a + 1, b + 1, 2);
	}
	else if (d == 2) {
		DFS(a + 1, b, 3);
		DFS(a, b+1, 1);
		DFS(a + 1, b + 1, 2);
	}
	else if (d == 3) {
		DFS(a + 1, b, 3);
		DFS(a + 1, b + 1, 2);
		
	}
	else {
		cout << "hello world" << endl;
	}
	}
	
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	DFS(1, 2, 1);
	cout << cnt << endl;

	
}