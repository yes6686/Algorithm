#include <iostream>
#include <string.h>
using namespace std;

int arr[51][10];
int arrS[51][10];
int isArr[4];
int n;
int maxAns = 0;
int visited[10];
int ss[10];

void sol() {
	int oc = 0;
	int score = 0;
	int index = 1;
	for (int i = 1; i <= n; i++) {
		oc = 0;
		memset(isArr, 0, sizeof(isArr));
		while (1) {
			if (arr[i][ss[index]] == 0) {
				oc++; 	
			}
			else  {
				int k = arr[i][ss[index]];
				for (int j = 3; j >= 1; j--) {
					if (isArr[j]==1) {
						if (j + k >= 4) {
							score+=1;
							isArr[j] = 0;
						}
						else {
							isArr[j + k] = 1;
							isArr[j] = 0;
						}
					}
				}
				if (k == 4) {
					score+=1;
				}
				else {
					isArr[k] = 1;
				}
			}
			
			index++;		
			if (index == 10) {
				index = 1;
			}
			if (oc == 3) {
				break;
			}
		}
	}
	maxAns = max(maxAns, score);
}


void dfs(int d) {
	if (d == 10) {
		sol();
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			ss[i] = d;
			dfs(d + 1);
			visited[i] = 0;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
		}
	}

	ss[4] = 1;
	visited[4] = 1;
	dfs(2);
	cout << maxAns;
}