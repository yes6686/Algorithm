#include <iostream>
#include <string>
using namespace std;

int arr[10];

string n;
int mi;
void dfs(int depth, string x,int c) {
	if (depth > n.size()) return;
	if (depth >0) {
		if (mi > abs(stoi(n) - stoi(x))+depth) {
			mi = abs(stoi(n) - stoi(x)) +depth;
		}
		for (int i = 0; i <= 9; i++) {
			string kk = x;
			if (arr[i] != -1) {
				kk += to_string(i);
				if (mi > abs(stoi(n) - stoi(kk)) + n.size()+1) {
					mi = abs(stoi(n) - stoi(kk)) + n.size()+1;
				}
			}
		}
	}
	
	if (arr[n[depth] - '0'] != -1) {
		if (depth == 0) {
			for (int i = 0; i <= 9; i++) {
				if (arr[i] != -1)
					dfs(depth + 1, x + to_string(i), 0);
			}
		}
		else {
			if (arr[n[depth-1] - '0'] == -1 || c==0) {
				for (int i = 0; i <= 9; i++) {
					if(arr[i]!=-1)
						dfs(depth + 1, x + to_string(i), 0);
				}
			}
			else {
				dfs(depth + 1, x + n[depth], 1);
			}
		}
	}
	else {
		for (int i = 0; i <= 9; i++) {
			if (arr[i] != -1)
				dfs(depth + 1, x + to_string(i), 0);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n;
	cin >> m;
	int x;
	mi = abs(stoi(n) - 100);
	for (int i = 0; i < m; i++) {
		cin >> x;
		arr[x] = -1;
	}
	dfs(0, "",1);
	cout << mi;
}