#include <iostream>
#include <map>
using namespace std;
int main() {
  map<string, int> m = {
    {"Poblano", 1500},
    {"Mirasol", 6000},
    {"Serrano", 15500},
    {"Cayenne", 40000},
    {"Thai", 75000},
    {"Habanero", 125000}
  };
  int n; 
  cin >> n;
  int totlaSHU = 0;
  for (int i = 0; i < n; i++) {
    string pepper; cin >> pepper;
    totlaSHU += m[pepper];
  }
  cout << totlaSHU << "\n";
}