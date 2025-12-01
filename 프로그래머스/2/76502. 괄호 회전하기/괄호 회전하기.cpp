#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

stack<char>st;

int solve(string s){
    
    for(int i=0;i<s.size();i++){
        char c = s[i];
        
        if(c==')' || c==']' || c=='}'){
            if(st.empty()) return 0;
        }
        if(c=='(' || c=='[' || c=='{'){
            st.push(c);
        }else if(c==')'){
           if(st.top()=='('){
               st.pop();
           } else{
               return 0;
           }
        }else if(c==']'){
            if(st.top()=='['){
               st.pop();
           } else{
               return 0;
           }
        }else if(c=='}'){
            if(st.top()=='{'){
               st.pop();
           } else{
               return 0;
           }
        }
    }
    
    if(st.empty()){
        return 1;
    }else{
        while(!st.empty()) st.pop();
        return 0;
    }
}

int solution(string s) {
    int answer = 0;
    
    answer += solve(s);
    
    for(int i=0;i<s.size()-1;i++){
        s = s.substr(1) + s[0];
        answer += solve(s);
    }
    
    return answer;
}