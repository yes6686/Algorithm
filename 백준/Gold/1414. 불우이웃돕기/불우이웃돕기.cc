#include <iostream>
#include <algorithm>
using namespace std;

int parent[51];
struct edge {
	int a, b;
	int cost;
};


edge Ed[2501];
int GetParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = GetParent(parent[x]);
}

void unionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;

}

int findParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a == b) return 1;
	else return 0;

}

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}

string w[51];
int main() { //a~z 1~26  A~Z 27~52
	int n; // n<=50 자연수
	cin >> n;
	
	int s = 0;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int totalCost = 0;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		for (int j = 0; j < w[i].size(); j++) {
			
			if (w[i][j] != '0') {
				Ed[s].a = i+1;
				Ed[s].b = j+1;
				if (w[i][j]  >= 97) {
					Ed[s].cost = w[i][j]-'a'+1;
					totalCost += Ed[s].cost;
				}
				else {
					Ed[s].cost = w[i][j] - 'A' + 27;
					totalCost += Ed[s].cost;
				}
				s++;
				
			
			}
		}
	}
	sort(Ed, Ed + s, compare);
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < s; i++) {
		if (!findParent(Ed[i].a, Ed[i].b)) {
			unionParent(Ed[i].a, Ed[i].b);
			sum += Ed[i].cost;
			cnt++;
		}
	}
	if (cnt == n - 1)
		cout << totalCost-sum;
	else
		cout << -1;
}