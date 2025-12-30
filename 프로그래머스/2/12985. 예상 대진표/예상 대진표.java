import java.util.*;

class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 1;

        int[] arr = new int[n];
        
        for(int i=0;i<n;i++) arr[i] = i+1;
        
        // 0 1 2 3 4 5 6 7 8
        
        while(n>1){
            
            int check=0;
            for(int i=0;i<n;i+=2){
                if((arr[i]==a && arr[i+1]==b) || (arr[i]==b && arr[i+1]==a)){
                    check=1;
                    break;
                }
                if(arr[i+1]==a){
                    arr[(i+1)/2] = a;
                }else if(arr[i+1]==b){
                    arr[(i+1)/2] = b;
                }else{
                    arr[(i+1)/2] = arr[i];
                }
            }
            if(check==1) break;
            
            n/=2;
            answer++;
        }
        
        return answer;
    }
}