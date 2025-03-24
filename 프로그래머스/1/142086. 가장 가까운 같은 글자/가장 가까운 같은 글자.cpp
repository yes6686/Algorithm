#include <string>
#include <vector>

using namespace std;

int alpha[27];

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i=0;i<s.size();i++){
        if(alpha[s[i]-'a']==0){
            answer.push_back(-1);
            alpha[s[i]-'a']=i+1;
        }else{
            answer.push_back((i+1)-alpha[s[i]-'a']);
            alpha[s[i]-'a'] = i+1;
        }
    }
    
    
    return answer;
}