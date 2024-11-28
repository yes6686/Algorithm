#include <string>
#include <vector>

using namespace std;

int solution(vector<int> w, vector<int> b) {
    int ans = 0;
    
    while(1){
        if((w[0]>= b[0] && w[1] >=b[1]) || (w[0]>= b[1] && w[1] >=b[0])) {
            break;
        }
       else{
        if(b[1]>b[0]){
            b[1]/=2;
        }else{
            b[0]/=2;
        }
        ans++;
        }
    }
    
    
    return ans;
}