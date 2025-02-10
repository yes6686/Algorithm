#include <string>
#include <vector>

using namespace std;

int alpha[27];

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i=0;i<keymap.size();i++){
        for(int j=0;j<keymap[i].size();j++){
            if(alpha[keymap[i][j]-'A']==0){
                alpha[keymap[i][j]-'A'] = j+1;
            }else{
                alpha[keymap[i][j]-'A'] = min(alpha[keymap[i][j]-'A'],j+1);
            }
        }
    }
    
    for(int i=0;i<targets.size();i++){
        int sum=0;
        for(int j=0;j<targets[i].size();j++){
            if(alpha[targets[i][j]-'A']==0) {
                sum = -1;
                break;
            }
            sum+=alpha[targets[i][j]-'A'];
        }
            answer.push_back(sum);   
    }
    
    return answer;
}