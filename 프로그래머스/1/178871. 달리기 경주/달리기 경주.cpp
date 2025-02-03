#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string,int>mp;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    for(int i=0;i<players.size();i++){
        mp[players[i]]=i;
    }
    for(int i=0;i<callings.size();i++){
        int idx = mp[callings[i]];
        string temp = players[idx];
        players[idx] = players[idx-1];
        players[idx-1] = temp;
        mp[players[idx]] = idx;
        mp[players[idx-1]] = idx-1; 
    }
    for(int i=0;i<players.size();i++){
        answer.push_back(players[i]);
    }
    return answer;
}