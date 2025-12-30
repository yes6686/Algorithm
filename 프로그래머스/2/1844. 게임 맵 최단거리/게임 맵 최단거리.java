import java.util.*;

class Solution {
    
    private static class Des{
        int x;
        int y;
        int cnt;
        public Des(int x,int y, int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
    
    private static int[] dx = {1,-1,0,0};
    private static int[] dy = {0,0,1,-1};
    private static boolean[][] visited;
    private static int answer = -1;
    
    
    private static void bfs(int n, int m, int[][] maps){
        Queue<Des> queue = new ArrayDeque<>();
        queue.add(new Des(0,0,1));
        visited = new boolean[n+1][m+1];
        visited[0][0]=true;
        
        while(!queue.isEmpty()){
            Des now = queue.poll();
            for(int i=0;i<4;i++){
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                int nc = now.cnt + 1;
                if(nx < 0 || ny < 0 || nx>=n || ny>=m) continue;
                if(visited[nx][ny]==true || maps[nx][ny]==0) continue;
                visited[nx][ny] = true;
                if(nx ==n-1 && ny ==m-1){
                    answer = nc;
                    return;
                }
                queue.add(new Des(nx,ny,nc));
                
            }
        }
        
    }
    
    public int solution(int[][] maps) {
        bfs(maps.length, maps[0].length, maps);
        
        return answer;
    }
}