#include <string>
#include <vector>
#include <stack>

using namespace std;


stack<int>stk;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    
    for(int i=0;i<ingredient.size();i++){
        if(stk.size()==0){
            if(ingredient[i]==1) stk.push(ingredient[i]);
        }else{
            int k = stk.top();
            if(ingredient[i]==1){ 
                if(k==3){
                    for(int j=0;j<3;j++) {
                        stk.pop();
                    }
                    answer++;
                }else{
                    stk.push(ingredient[i]);
                }
                
            }else{
                if(ingredient[i] - k ==1){
                    stk.push(ingredient[i]);                   
                }else{
                    while(!stk.empty()) stk.pop();
                }
            }            
        }
    }
    
    return answer;
}