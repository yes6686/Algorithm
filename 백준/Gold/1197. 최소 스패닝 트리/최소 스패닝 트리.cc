#include <iostream>	
#include <algorithm>
using namespace std;

int parent[10001];
int cc[10001];
struct con {
	int a;
	int b;
	int c;
};
bool compare(con w, con h) {
	return w.c < h.c;
}

int getParent(int x) {
	if (parent[x] == x) return x;
	return getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	con s[100001];
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < e; i++) {
		cin >> s[i].a >> s[i].b >> s[i].c;
		
	}
	
	sort(s, s + e,compare);
	int sum = 0;
	for (int i = 0; i < e; i++) {
		if (cc[s[i].a] == 1 && cc[s[i].b] == 1 && findParent(s[i].a, s[i].b) == 1) {
			continue;
		}
		unionParent(s[i].a, s[i].b);
		cc[s[i].a] = 1;
		cc[s[i].b] = 1;
		sum += s[i].c;
	}
	cout << sum << '\n';







}