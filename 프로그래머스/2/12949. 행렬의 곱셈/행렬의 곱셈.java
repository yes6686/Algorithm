class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer;
        
        int r1 = arr1.length;
        int c1 = arr1[0].length;
        
        int r2 = arr2.length;
        int c2 = arr2[0].length;
        
        answer = new int[r1][c2];
        
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){     
                for(int t=0;t<c1;t++){
                    answer[i][j]+=(arr1[i][t] * arr2[t][j]);
                } 
            }
        }
        
        
        
        return answer;
    }
}