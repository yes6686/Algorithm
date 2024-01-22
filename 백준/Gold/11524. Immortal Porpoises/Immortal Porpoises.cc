#include <iostream>
#include <map>
#define MOD 1000000000
using namespace std;

typedef long long int ll;

map<ll, ll> mp;

ll f(ll n) {
	if (mp[n]) return mp[n];
	if (n == 0)return mp[n]= 0;
	else if (n == 1)return mp[n]=1;
	else if (n == 2) return mp[n]=1;
	else {
		if (n % 2 == 0) {
			return mp[n]=(f(n / 2) * (f(n / 2 + 1) + f(n / 2 - 1)))%MOD;
		}
		else {
			return mp[n]=(((f((n + 1) / 2) * f((n + 1) / 2))%MOD) + (f((n - 1) / 2) * f((n - 1) / 2))%MOD)%MOD;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	int T;
	cin >> T;
	int x;
	while (T--) {
		cin >>x>> n;
		if (n == -1) break;
		cout <<x<<" "<< f(n) << '\n';
	}
}