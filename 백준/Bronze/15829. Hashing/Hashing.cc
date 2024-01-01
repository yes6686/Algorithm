#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);	
	
	int n;
	cin >> n;
	string s;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		s.push_back(c);
	}
	long long int sum = 0;
	long long int k = 1;
	for (int i = 0; i < n; i++) {
		sum = (sum+(s[i]-96)*k)% 1234567891;
		k = (k*31)%1234567891;
		
	}
	cout << sum;

}