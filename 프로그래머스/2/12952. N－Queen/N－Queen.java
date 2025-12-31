class Solution {
    
    private static int N, answer = 0;
    private static final int[] dx = {1,1,-1,-1};
    private static final int[] dy = {-1,1,-1,1};
    
    private static void updateMap(int[][] map, int x, int y){
    
        for(int i=0;i<N;i++){
            map[x][i] = 1;
            map[i][y] = 1;
        }
        for(int i=0;i<4;i++){
            int nx = x;
            int ny = y;
            while(true){
                nx += dx[i];
                ny += dy[i];
                if(nx<0 || ny<0 || nx>=N || ny>=N) break;
                map[nx][ny] = 1;
            }
        }
        
        
    }
    
    private static void bt(int[][] map, int r){
        
        
        if(r==N) {
            answer++;
            return;
        }
        for(int i=0;i<N;i++){
            if(map[r][i]==0){
                int[][] uMap = new int[N][N];
                for(int t=0;t<N;t++){
                    uMap[t] = map[t].clone();
                }
                updateMap(uMap, r,i);
                bt(uMap, r + 1);
            }
            
        }
    }
    
    public int solution(int n) {
        N = n;
        int[][] map = new int[n][n];
        bt(map,0);
        
        return answer;
    }
}