#include <iostream>
using namespace std;

long long int dp[41]; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;

	if (n == m) { // 모든 좌석이 VIP~
		cout << 1;
		return 0;
	}

	int x;
	dp[0] = 1; // 아래에서 설명
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int ans = 1; //방법의 가짓수는 2,000,000,000을 넘지 않기에 int형 사용
	int preVipPosition = 0; // 전에 나온 vip 위치

	for (int i = 0; i < m; i++) { //고정석의 번호가 작은 수부터 큰 수의 순서로 한 줄에 하나씩 입력되므로
		cin >> x;
		ans *= dp[x - 1 - preVipPosition]; 
		// *만약  vip가 연속으로 나올 시 dp[0]이 곱해질 수 있으므로 dp[0]=1로 해줘야함
		preVipPosition = x;
	}
	ans *= dp[n - preVipPosition];
	cout << ans;	
}
