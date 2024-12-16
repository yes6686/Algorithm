#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<pair<string,string>,int>mp1;
map<string,int>mp2;
map<string,int>ans;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for(int i=0;i<friends.size();i++){
        mp2[friends[i]]=0;
        ans[friends[i]]=0;
    }
    
    for(int i=0;i<friends.size()-1;i++){
        for(int j=i+1;j<friends.size();j++){
            string s1 = friends[i];
            string s2 = friends[j];
            mp1[{s1,s2}]=0;
            mp1[{s2,s1}]=0;
        }
    }
    
    
    
    for(int i=0;i<gifts.size();i++){
        string s = gifts[i];
        for(int j=0;j<s.size();j++){
            if(s[j]==' '){
                string s1 = s.substr(0,j);
                string s2 = s.substr(j+1);
                mp1[{s1,s2}]++;
                mp2[s1]++;
                mp2[s2]--;
                break;
            }
        }
    }
    for(int i=0;i<friends.size();i++){
        cout<<friends[i]<<" : "<<mp2[friends[i]]<<'\n';
    }
    
    
    for(int i=0;i<friends.size()-1;i++){
        for(int j=i+1;j<friends.size();j++){
            string s1 = friends[i];
            string s2 = friends[j];
            if(mp1[{s1,s2}]>mp1[{s2,s1}]){
                ans[s1]++;
                answer=max(answer,ans[s1]);
            }else if(mp1[{s1,s2}]<mp1[{s2,s1}]){
                ans[s2]++;
                answer=max(answer,ans[s2]);
            }else{
                if(mp2[s1]>mp2[s2]){
                    ans[s1]++;
                    answer=max(answer,ans[s1]);
                }else if(mp2[s1]<mp2[s2]){
                    ans[s2]++;
                    answer=max(answer,ans[s2]);
                }
            }
        }
    }
    
  
    
    return answer;
}