#include <iostream>
using namespace std;

int main() {
  int hh, mm; 
  cin >> hh >> mm;
  int startTime = 9 * 60;
  int submitTime = hh * 60 + mm;
  int timeConsumed = submitTime - startTime;
  cout << timeConsumed << "\n";
}