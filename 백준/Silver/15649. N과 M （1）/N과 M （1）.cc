#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int arr[9];
int n, m;
queue<int>q;
vector<int>v[10];
int c[10];
int d[10];
void dfs(string s,int depth,int k) {
	if (c[k]) return; 
	c[k] = 1;
	if (depth >= m) {
		cout << s << '\n';

		return;
	}
	int check = 1;
	for (int i = 0; i < v[k].size(); i++) {
		int y = v[k][i];
		dfs(s + ' ' + to_string(y), depth + 1, y);
		for (int i = 0; i < s.size(); i++) {
			if (s[i]-'0'==y) {
				check = 0;
			}
		}
		
		if(check)
		c[y] = 0;
		else {
			check = 1;
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				v[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dfs(to_string(i), 1, i);
		for (int i = 0; i < 10; i++) {
			c[i] = 0;
		}
	}
		
}

	
