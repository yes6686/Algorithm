#include <iostream>
#include <string>

#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int i1 = 0;
    int i2 = 0;
    
    for(int i=0;i<goal.size();i++){
        if(cards1[i1]==goal[i]){
            i1++;
        }else if(cards2[i2]==goal[i]){
            i2++;
        }else{
            answer = "No";
            break;
        }
    }
    if(answer=="") answer="Yes";
    
    return answer;
}