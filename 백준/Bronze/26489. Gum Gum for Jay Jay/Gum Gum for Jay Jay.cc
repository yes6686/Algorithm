#include <iostream>
using namespace std;
int main() {
  string line = ""; 
  int cntLine = 0;
  while (getline(cin, line))
    cntLine++;
  cout << cntLine << "\n";
}