#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cal(string s){
    int sum=0;
    string ss="";
    for(int i=0;i<s.size();i++){
        if(s[i]==':'){
            sum += stoi(ss)*60;
            ss="";
        }else{
            ss+=s[i];
        }
    }
    sum += stoi(ss);
    //cout<<"sum : "<<sum<<'\n';
    return sum;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> c) {
    int len = cal(video_len);
    int p = cal(pos);
    int st = cal(op_start);
    int en = cal(op_end);
    
    if(st<=p && p<=en){
        p = en;
    }
    
    for(int i=0;i<c.size();i++){
        if(c[i]=="next"){
            
            p+=10;
            if(p>len){
                p = len;
            }
            
        }else{
            p-=10;
            if(p<0) p =0;
        }
        if(st<=p && p<=en){
        p = en;
        }
    }
    
    string ans ="";
    
    if(p/60>=10){
        ans+=to_string(p/60);
    }else{
        ans+='0';
        ans+=to_string(p/60); 
    }
    ans+=':';
    
    if(p%60>=10){
        ans+=to_string(p%60);
    }else{
        ans+='0';
        ans+=to_string(p%60); 
    }
    
    return ans;
}