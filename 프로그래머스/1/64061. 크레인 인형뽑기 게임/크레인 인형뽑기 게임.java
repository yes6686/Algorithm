import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        
        int r = board.length;
        int c = board[0].length;
        
        Stack<Integer>stack = new Stack<>();
        
        int n = moves.length;
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            int k = moves[i] - 1;
            for(int j=0;j<r;j++){
                if(board[j][k]!=0){
                    cnt++;
                    if(stack.empty()) stack.push(board[j][k]);
                    else{
                        if(stack.peek() == board[j][k]){
                            stack.pop();
                        }else{
                            stack.push(board[j][k]);
                        }
                    }
                    board[j][k] =0;
                    break;
                }
            }
        }
        
        return cnt - stack.size();
    }
}