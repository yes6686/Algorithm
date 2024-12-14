#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int arr[51][51];

bool compare(int a, int b){
    return a>b;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(), mats.end(), compare);
    
    int rows = park.size();
    int cols = park[0].size();
    cout<<rows<<" , "<<cols<<'\n';
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(park[i][j]=="-1"){
                arr[i][j] = 0;
            }else{
                arr[i][j]=1;
            }
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    
    for(int k : mats){
        for(int a=0;a<=rows-k;a++){
            for(int b=0;b<=cols-k;b++){
                int check=1;
                for(int h=a;h<a+k && check==1;h++){
                    for(int f=b;f<b+k;f++){
                        if(arr[h][f]==1){
                            check=0;
                            break;
                        }
                    }
                }
                if(check==1){
                    return k;
                }
            }
        }
    }
    
    return -1;
}