#include <iostream>
#include <vector>
using namespace std;

int N, cluster;
long long int f, n = 0;
vector<int> files;
int main(int argc, char **argv){
  scanf("%d", &N);
  
  for(int i = 0; i < N; i++){
    scanf("%lld", &f);
    files.push_back(f);
  }

  scanf("%d", &cluster);

  for(int i = 0; i < N; i++){
    if(files[i] > cluster){
      if(files[i] % cluster == 0){
        n += files[i] / cluster;
      } else {
        n += files[i] / cluster + 1;
      }
    } else if (files[i] != 0){
      n += 1;
    }
  }

  printf("%lld", n * cluster);
  return 0;
}