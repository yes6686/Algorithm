#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    
    while(T--){
        long long int n;
        cin>>n;
        long long int sum =0;
        for(int i=0;i<n;i++){
            long long int x;
            cin>>x;
            sum = (sum+x)%n;
        }
        if(sum%n==0){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
}