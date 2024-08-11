#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double a;
  while(true){
    cin >> a;
    if(a == 0) break;
    printf("%.2f\n", 1 + a + pow(a,2) + pow(a,3) + pow(a,4));
  }
}