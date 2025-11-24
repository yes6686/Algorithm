#include <string>
#include <vector>

using namespace std;

int arrX[10];
int arrY[10];

string solution(string X, string Y) {
    string answer = "";
    
    for(char x : X){
        arrX[x-'0']++;
    }
    
    for(char y : Y){
        arrY[y-'0']++;
    }
    
    for(int i=9;i>=0;i--){
        int x = (arrX[i] > arrY[i]) ? arrY[i] : arrX[i]; 
        for(int j=0;j<x;j++) answer+= to_string(i);
    }
    
    if(answer=="") answer="-1";
    else if(answer[0]=='0') answer="0";
    
    return answer;
}