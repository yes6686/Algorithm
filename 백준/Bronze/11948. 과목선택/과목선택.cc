#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr1[4], arr2[2], sum = 0;
    for(int i=0; i<4; i++){
        cin>>arr1[i];
    }
    for(int i=0; i<2; i++){
        cin>>arr2[i];
    }
    
    sort(arr1, arr1+4);
    sort(arr2, arr2+2);
    
    for(int i=1; i<4; i++){
        sum += arr1[i];
    }
    sum += max(arr2[0], arr2[1]);
    cout<<sum;
}