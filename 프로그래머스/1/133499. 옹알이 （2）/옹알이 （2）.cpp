#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i=0;i<babbling.size();i++){
        string s = babbling[i];
        int check=1;
        int conCheck=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='a'){
                if(j+2 < s.size()){
                    if(s[j+1]=='y' && s[j+2]=='a') {
                        if(conCheck==1){
                            check=0;
                            break;
                        }
                        conCheck=1;
                        j+=2;
                    }else{
                        check=0;
                        break;
                    }
                }else{
                    check=0;
                    break;
                }
            }else if(s[j]=='y'){
                if(j+1 < s.size()){
                    if(s[j+1]=='e') {
                        j+=1;
                        if(conCheck==2){
                            check=0;
                            break;
                        }
                        conCheck=2;
                    }else{
                        check=0;
                        break;
                    }
                }else{
                    check=0;
                    break;
                }
            }else if(s[j]=='w'){ 
                if(j+2 < s.size()){
                    if(s[j+1]=='o' && s[j+2]=='o') {
                        j+=2;
                        if(conCheck==3){
                            check=0;
                            break;
                        }
                        conCheck=3;
                    }else{
                        check=0;
                        break;
                    }
                }else{
                    check=0;
                    break;
                }
            }else if(s[j]=='m'){
                if(j+1 < s.size()){
                    if(s[j+1]=='a') {
                        j+=1;
                        if(conCheck==4){
                            check=0;
                            break;
                        }
                        conCheck=4;
                    }else{
                        check=0;
                        break;
                    }
                }else{
                    check=0;
                    break;
                }
            }else{
                check=0;
                break;
            }
        }
        if(check==1) answer++;
    }
    
    return answer;
}