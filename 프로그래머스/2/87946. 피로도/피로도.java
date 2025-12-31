class Solution {
    
    private static int answer = 0;
    private static boolean[] visited;
    
    public int solution(int k, int[][] dungeons) {
        visited = new boolean[dungeons.length+1];
        
        bt(k,0,dungeons);
        
        return answer;
    }
    
    private static void bt(int Hp, int cnt, int[][]dg){
        
        for(int i=0;i<dg.length;i++){
            if(!visited[i] && dg[i][0] <=Hp){
                visited[i] = true;
                bt(Hp - dg[i][1], cnt+1, dg);
                visited[i] = false;
            }
        }
        answer = Math.max(answer, cnt);
    }
}