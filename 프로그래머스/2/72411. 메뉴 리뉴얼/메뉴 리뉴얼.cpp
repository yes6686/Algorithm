#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int visited[11];
int check[11];
unordered_map<string,int>mp;

void bt(int d,string s){
    for(int i=d;i<s.size();i++){
        if(visited[i]==0){
            visited[i]=1;
            bt(i+1,s);
            visited[i]=0;
        }
    }
    string st = "";
    for(int i=0;i<s.size();i++){
        if(visited[i]==1){
            st+=s[i];
        }
    }
    if(check[st.size()]==1){
        mp[st]++;
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int c : course){
        check[c]=1;
    }
    
    for(string &s : orders){
        sort(s.begin(),s.end());
        bt(0,s);
    }
    
    for(int c : course){
        int maxOrder = 0;
        for(pair<string,int> e : mp){
            if(e.first.size()==c)
                maxOrder = max(maxOrder,e.second);
        }
        if(maxOrder <= 1) continue;
        for(pair<string,int> e : mp){
            if(maxOrder == e.second && e.first.size()==c){
                answer.push_back(e.first);
            }
        }
    }
    sort(answer.begin(),answer.end());// 사전순으로 정렬
    
    
    return answer;
}