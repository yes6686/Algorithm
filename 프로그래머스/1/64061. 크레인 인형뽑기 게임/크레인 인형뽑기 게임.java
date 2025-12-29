import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        
        int n = board.length;
        
        Stack<Integer>[] lanes = new Stack[n];
        
        for(int i=0;i<n;i++){
            lanes[i] = new Stack<>();
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(board[i][j] > 0){
                    lanes[j].push(board[i][j]);
                }
            }
        }
        
        Stack<Integer> bucket = new Stack<>();
        
        int answer=0;
        
        for(int move : moves){
            int k = move - 1;
            if(!lanes[k].isEmpty()){
                int e = lanes[k].pop();
                if(!bucket.isEmpty()){
                    if(e==bucket.peek()){
                        bucket.pop();
                        answer+=2;
                    }else{
                        bucket.push(e);
                    }
                }else{
                    bucket.push(e);
                }
            }
        }
        
        
        return answer;
    }
}