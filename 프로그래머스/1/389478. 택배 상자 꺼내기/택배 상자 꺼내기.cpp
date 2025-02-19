#include <string>
#include <vector>

using namespace std;

int arr[102][102];

int solution(int n, int w, int num) {
    int answer = 0;
    int i = 1;
    int j = 1;
    int s = 1;
    int check = 0;
    int ai,aj;
    while(true){
        if(check==0){
            arr[i][j] = s;
            if(s==num) {
                ai = i;
                aj = j;
            }
        }else{
            arr[i][w-j+1] = s;
            if(s==num) {
                ai = i;
                aj = w-j+1;
            }
        }
        s++;
        if(s>n) break;
        if(j==w){
            i++;
            check = (check==1) ? 0 : 1;
            j=1;
        }else{
            j++;
        }
    }
    while(true){
        if(arr[ai][aj]>=num){
            answer++;
            ai++;
        }else{
            break;
        }
    }
    
    return answer;
}