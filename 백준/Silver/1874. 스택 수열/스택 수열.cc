#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int arr[100001];
stack<int>s;
vector<char>v;
int main() {
	string a;
	ios_base::sync_with_stdio(false); //동기화를 비활성화
	cin.tie(NULL);	// cin과 cout의 묶음을 풀어줌.
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k = 0;
	int j = 0;
	while(j<n){
		if (k < arr[j]) {
			for (int i = k + 1; i <= arr[j]; i++) {
				s.push(i);
				v.push_back('+');
			}
			s.pop();
			v.push_back('-');
			k = arr[j];
			j++;
		}
		else {
			if (s.top() == arr[j]) {
				v.push_back('-');
				s.pop();
				j++;	
			}
			else {
				cout << "NO";
				return 0;
			}		
			
	}
}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	

}