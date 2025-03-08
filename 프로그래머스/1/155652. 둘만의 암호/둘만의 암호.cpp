#include <iostream>
#include <string>
#include <vector>

int skipAlpha[27];

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0;i<skip.size();i++){
        skipAlpha[skip[i]-'a']=1;
    }
    
    for(int i=0;i<s.size();i++){
        int idx = index;
        char ss = s[i];
        while(idx){
            ss+=1;
            if(ss>'z'){
                    ss='a';
                }
            if(skipAlpha[ss-'a']==1){
                continue;
            }else{
                idx--;
            }
        }
        answer+=ss;
    }
    
    return answer;
}