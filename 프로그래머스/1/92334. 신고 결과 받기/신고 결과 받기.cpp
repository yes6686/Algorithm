#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int>mp;
map<string,int>ans;
map<string,int>ch1;
map<string,int>ch2;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(int i=0;i<report.size();i++){
        string s= "";
        for(int j=0;j<report[i].size();j++){
            if(report[i][j]==' ') {
                s="";
                continue;
            }
            s+=report[i][j];
        }
        if(ch1[report[i]]==0){
            ch1[report[i]]=1;
            mp[s]++;
        }
    }
    
    for(int i=0;i<report.size();i++){
        string s1= "";
        string s= "";
        for(int j=0;j<report[i].size();j++){
            if(report[i][j]==' ') {
                s1=s;
                s="";
                continue;
            }
            s+=report[i][j];
        }
         if(ch2[report[i]]==0){
            ch2[report[i]]=1;
            if(mp[s]>=k) ans[s1]++;
        }
    }
    
    for(string s : id_list){
        answer.push_back(ans[s]);
    }
    
    
    return answer;
}