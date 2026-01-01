import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        int s = 0;
        for(int i=0;i<commands.length;i++){
            int n = commands[i][1] - commands[i][0] + 1;
            int[] arr = new int[n];
            
            for(int j=0;j<n;j++){
                arr[j] = array[commands[i][0] + j - 1];
            }
            Arrays.sort(arr);
            answer[s++] = arr[commands[i][2] - 1];
        }
        
        return answer;
    }
}