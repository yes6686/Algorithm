#include <iostream>
#include <string>
using namespace std;
int main(){
    string s="WelcomeToSMUPC";
    int N;
    cin >> N; 
    N--;
    cout << s[N % 14];
}