#include <iostream>
using namespace std;

int arr[10][10];

/* 다섯 종류의 색종이 갯수 초기화*/
int leftSquare1x1Cnt = 5;
int leftSquare2x2Cnt = 5;
int leftSquare3x3Cnt = 5;
int leftSquare4x4Cnt = 5;
int leftSquare5x5Cnt = 5;

int ans = 26;

int isSquareNxN(int a,int b,int N) {
	int cnt = 0;
	if (a + N > 10 || b + N > 10) return 0;
	for (int i = a; i < a + N; i++) {
		for (int j = b; j < b + N; j++) {
			if (arr[i][j] == 1) cnt++;
		}
	}
	return cnt == N*N ? 1 : 0;
}

void SquareNxNChangeToZero(int a, int b,int N) {
	for (int i = a; i < a + N; i++) {
		for (int j = b; j < b + N; j++) {
			arr[i][j] = 0;
		}
	}
}

void SquareNxNChangeToOne(int a, int b, int N) {
	for (int i = a; i < a + N; i++) {
		for (int j = b; j < b + N; j++) {
			arr[i][j] = 1;
		}
	}
}

void solve(int a,int b,int u) {
	if (ans < u)return;
	if (a == 10) {
		int isAllZero = 1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] != 0) {
					isAllZero = 0;
					break;
				}
			}
			if (isAllZero == 0) break;
		}
		if (isAllZero == 1) {
			if (ans > u) {
				ans = u;
			}
		}
		return;
	}
	if (arr[a][b] == 1) {
	for (int N = 5; N >= 1; N--) {
			if (isSquareNxN(a, b, N) == 1) {
				if (N == 1) {
					if (leftSquare1x1Cnt > 0) {
						leftSquare1x1Cnt -= 1;
						SquareNxNChangeToZero(a, b, N);
						if (b == 9) {
							solve(a + 1, 0, u + 1);
						}
						else {
							solve(a, b + 1, u + 1);
						}
						SquareNxNChangeToOne(a, b, N);
						leftSquare1x1Cnt += 1;
					}
				}
				else if (N == 2) {
					if (leftSquare2x2Cnt > 0) {
						leftSquare2x2Cnt -= 1;
						SquareNxNChangeToZero(a, b, N);
						if (b == 9) {
							solve(a + 1, 0, u + 1);
						}
						else {
							solve(a, b + 1, u + 1);
						}
						SquareNxNChangeToOne(a, b, N);
						leftSquare2x2Cnt += 1;
					}
				}
				else if (N == 3) {
					if (leftSquare3x3Cnt > 0) {
						leftSquare3x3Cnt -= 1;
						SquareNxNChangeToZero(a, b, N);
						if (b == 9) {
							solve(a + 1, 0, u + 1);
						}
						else {
							solve(a, b + 1, u + 1);
						}
						SquareNxNChangeToOne(a, b, N);
						leftSquare3x3Cnt += 1;
					}
				}
				else if (N == 4) {
					if (leftSquare4x4Cnt > 0) {
						leftSquare4x4Cnt -= 1;
						SquareNxNChangeToZero(a, b, N);
						if (b == 9) {
							solve(a + 1, 0, u + 1);
						}
						else {
							solve(a, b + 1, u + 1);
						}
						SquareNxNChangeToOne(a, b, N);
						leftSquare4x4Cnt += 1;
					}
				}
				else if (N == 5) {
					if (leftSquare5x5Cnt > 0) {
						leftSquare5x5Cnt -= 1;
						SquareNxNChangeToZero(a, b, N);
						if (b == 9) {
							solve(a + 1, 0, u + 1);
						}
						else {
							solve(a, b + 1, u + 1);
						}
						SquareNxNChangeToOne(a, b, N);
						leftSquare5x5Cnt += 1;
					}
				}
			}
		}
	}
	else {
		if (b == 9) {
			solve(a + 1, 0, u);
		}
		else {
			solve(a, b + 1, u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0, 0);
    if(ans==26) cout<<-1;
    else
	    cout << ans;
}