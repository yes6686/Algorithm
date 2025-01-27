#include <iostream>
#include <string>
#include <vector>

using namespace std;

int attackTime[1001];
int attackDamage[1001];

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int r = attacks.size();
    for(int i=0;i<r;i++){
        attackTime[attacks[i][0]]=1;
        attackDamage[attacks[i][0]]=attacks[i][1];
    }
    int t = attacks[attacks.size()-1][0];
    int bandTime = bandage[0];
    int timeHeal = bandage[1];
    int addHeal = bandage[2];
    int h = health;
    int seqHeal = 0;
    for(int i=1;i<=t;i++){
        if(attackTime[i]==1){
            h-=attackDamage[i];
            seqHeal=0;
            if(h<=0) return -1;
        }else{
            h+=timeHeal;
            if(h>health) h = health;
            seqHeal++;
            if(seqHeal==bandTime){
                seqHeal=0;
                h+=addHeal;
                if(h>health) h = health;
            }
        }
    }
    return h;
}