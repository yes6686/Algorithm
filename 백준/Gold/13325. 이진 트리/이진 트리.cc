#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#define MAX 3000001
using namespace std;

vector<int>v[MAX];
int val[MAX];
int d[MAX];
void dfs(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		dfs(k);
		d[k / 2-1] = max(d[k / 2-1], val[k / 2 - 1] + d[k-1]);
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int x;
	for (int i = 1; i <= pow(2, n + 1) - 2; i++) {
		cin >> x;
		v[(i + 1) / 2].push_back(i + 1);
		val[i] = x;
		d[i] = x;
	}

	for (int i = pow(2,n)-1; i < pow(2, n + 1) - 2; i += 2) {
		int k = max(val[i], val[i + 1]);
		val[i] = k;
		val[i+1] = k;
	}

	dfs(1);
	int add = 0;
	for (int i = 1; i<pow(2, n) - 1; i+=2) {
		int k1 = abs(d[i]-d[i + 1]);
		//cout <<i << " ; " << "k1 : " << k1 << '\n';
		add += k1;
		
	}
	int sum = 0;
	for (int i = 1; i <= pow(2, n + 1) - 2; i++) {
		//cout << i << " : " << val[i] << '\n';
		sum += val[i];
		
	}
	cout << sum+add;
}


