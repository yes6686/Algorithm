#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int alpha[27];

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    istringstream s(today);
    string sb;
    int i=1;
    int tody = 0;
    while(getline(s, sb,'.')){
        if(i==1){
            tody += stoi(sb)*28*12;
        }else if(i==2){
            tody += stoi(sb)*28;
        }else{
            tody += stoi(sb); 
        }
        i++;
    }
    cout<<"tody : "<<tody<<'\n';
    
    for(int j=0;j<terms.size();j++){
        istringstream ssss(terms[j]);
        string ssb;
        i=1;
        vector<string>te;
        while(getline(ssss,ssb,' ')){
            te.push_back(ssb);
            cout<<"ssb : "<<ssb<<'\n';
        }
        alpha[te[0][0]-'A'] = stoi(te[1]);
        cout<<"alpha[te[0][0]-'A'] : "<<alpha[te[0][0]-'A']<<'\n';
    }
    
    for(int j=0;j<privacies.size();j++){
        istringstream sss(privacies[j]);
        string sbb;
        vector<string>te;
        while(getline(sss,sbb,' ')){
            te.push_back(sbb);
            cout<<"sbb : "<<sbb<<'\n';
        }
        istringstream ss(te[0]);
        string sbsb;
        i=1;
        int p =0;
        while(getline(ss,sbsb,'.')){
            if(i==1){
                p += stoi(sbsb)*28*12;
            }else if(i==2){
                p += stoi(sbsb)*28;
            }else{
                p += stoi(sbsb); 
        }
            i++;
        }
        cout<<"p : "<<p<<'\n';
        int k = alpha[te[1][0]-'A'];
        cout<<"k : "<<k<<'\n';
        p += (k*28);
        cout<<"pp : "<<p<<'\n';
        if(p-1 < tody){
            answer.push_back(j+1);
        }
    }
    
    return answer;
}