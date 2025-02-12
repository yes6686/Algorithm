#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    string a = "수";
    string b = "박";
    
    for(int i=0;i<n;i++){
        if(i%2==0){
            answer+=a;   
        }else{
          answer+=b;  
        } 
    }
    
    return answer;
}