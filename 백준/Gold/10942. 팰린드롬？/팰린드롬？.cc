#include <iostream>
using namespace std;

int arr[2001];
int r[2001][2001];
int check(int a, int b) {
	if (r[a][b] != 0) return r[a][b];
	if (a >= b) return 1;
	
	if (arr[a] == arr[b]) return r[a][b]=check(a+1,b-1);
	if (arr[a] != arr[b]) return r[a][b]= - 1;

	return r[a][b]=check(a+1,b-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	int s, e;
	int k;


	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		if (check(s,e) < 0) {
			cout << 0 << '\n';
		}
		else {
			cout << check(s,e) << '\n';
		}
	}
} 