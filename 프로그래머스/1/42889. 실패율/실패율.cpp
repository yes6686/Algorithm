#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double arr[502];
double k[502];

vector<pair<double,int>>v;

bool compare(pair<double,int> a, pair<double,int> b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int i=0;i<stages.size();i++){
        arr[stages[i]]++;
        for(int j=1;j<=stages[i];j++){
            k[j]++;
        }
    }
    
    for(int i=1;i<=N;i++){
        if(arr[i]==0 || k[i]==0) {
            v.push_back({0.0,i});
        }
        else v.push_back({(arr[i]/k[i]), i});
    }
    
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].second);
    }
    
    return answer;
}