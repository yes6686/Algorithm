#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char arr[16];

int L, C;

void recur(string s,int depth,int n1, int n2,int cnt) {

	if (depth > C) {
		return;
	}

	if (cnt == L) {
		if (n1 >= 1 && n2 >= 2) {
			cout << s << '\n';
			return;
		}
		else {
			return;
		}
	}
	if (arr[depth] == 'a' || arr[depth] == 'e' || arr[depth] == 'i' ||
		arr[depth] == 'o' || arr[depth] == 'u') {
		recur(s+arr[depth], depth + 1, n1 + 1, n2,cnt+1);
	}
	else {

		recur(s + arr[depth], depth + 1, n1, n2+1,cnt+1);
	}
	recur(s, depth + 1, n1, n2, cnt);
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> L >>C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);

	recur("", 0, 0, 0,0);

}