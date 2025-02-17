#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i=0;i<t.size()-p.size()+1;i++){
        string s = "";
        for(int j=i;j<i+p.size();j++){
            s+=t[j];
        }
        
        cout<<"s : "<<s<<'\n';
        if(s.size()<p.size()){
            answer++;
        }else if(s.size()==p.size()){
            int check = 1;
            for(int a=0;a<s.size();a++){
                if(s[a] == p[a]) continue;
                else if(s[a] < p[a]){
                    check=1;
                    break;
                }else {
                    check=0;
                    break;
                }
            }
            if(check==1) answer++;
        }        
    }

    
    
    return answer;
}