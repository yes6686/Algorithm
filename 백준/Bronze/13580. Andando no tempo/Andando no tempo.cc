#include <iostream>
#include <algorithm>
using namespace std;
int arr[3];
int main(){
    for(int i = 0; i < 3; i++) cin >> arr[i];
    sort(arr, arr + 3);
    if(arr[0] == arr[1] || arr[1] == arr[2] || arr[0] + arr[1] == arr[2]) cout << "S";
    else cout << "N";
}