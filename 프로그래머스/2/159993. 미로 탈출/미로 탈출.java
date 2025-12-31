import java.util.*;

class Solution {
    
    private static class Node{
        int x,y;
        int cnt;
        public Node(int x,int y, int cnt){
            this.x=x;
            this.y=y;
            this.cnt=cnt;
        }
    }
    
    private static final int[] dx = {1,-1,0,0};
    private static final int[] dy = {0,0,1,-1};
    //private static boolean[][] visited;
    
    private static int bfs(int x, int y, int n, int m, String[] maps, int check){
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(new Node(x,y,0));
        boolean[][] visited = new boolean[n][m];
        visited[x][y]= true;
        while(!queue.isEmpty()){
            Node curr = queue.poll();
            for(int i=0;i<4;i++){
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];
                int nc = curr.cnt + 1;
                if(nx <0 || ny<0|| nx>=n || ny>=m) continue;
                if(visited[nx][ny]) continue;
                char w = maps[nx].charAt(ny);
                if(w=='X') continue;
                visited[nx][ny] =true;
                if((check==1 && w=='L') || (check==2 && w=='E')){
                    //queue.clear();
                    return nc;
                }else{
                    queue.add(new Node(nx,ny,nc));
                }
            }
        }
        return 0;
    }
    
    
    public int solution(String[] maps) {
        int answer = 0;
        
        int si=0, sj=0;
        int li=0, lj=0;
        int n = maps.length;
        int m = maps[0].length();
        
        for(int i=0;i<n;i++){
            String map = maps[i];
            for(int j=0;j<m;j++){
                if(map.charAt(j)=='S'){
                    si=i;
                    sj=j;
                }else if(map.charAt(j)=='L'){
                    li = i;
                    lj = j;
                }
            }
        }
        
        int s = bfs(si,sj,n,m,maps,1);
        int e = bfs(li,lj,n,m,maps,2);
        
        
        return (s==0 || e==0) ? -1 : s+e;
    }
}