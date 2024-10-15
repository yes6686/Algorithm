#include <iostream>
using namespace std;
int main(){
  string s;
  int a=0, b=0;
  cin >> s;
  for(int i = 0; i < s.size(); i+=2){
    if(s[i] == 'A') a += s[i+1] - '0';
    else b += s[i+1] - '0';
  }
  if(a > b) cout << "A";
  else cout << "B";
}