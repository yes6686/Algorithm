import java.util.*;

class Solution {
    
    public static class Node{
        int x, y, cost;
        public Node(int x,int y, int cost){
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }
     
    public int solution(int[][] land, int height) {
        int answer = 0;
        int n = land.length;
        
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,1,-1};
        boolean[][] visited = new boolean[n][n];
        
        
        PriorityQueue<Node> pq = new PriorityQueue<>((o1,o2)->
            Integer.compare(o1.cost,o2.cost));
        pq.add(new Node(0,0,0));
        
        while(!pq.isEmpty()){
            Node curr = pq.poll();
            
            if(visited[curr.x][curr.y]) continue;
            visited[curr.x][curr.y] = true;
            answer+=curr.cost;
            
            for(int i=0;i<4;i++){
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                int diff = Math.abs(land[curr.x][curr.y] - land[nx][ny]);
                
                if(height >= diff){
                    pq.add(new Node(nx,ny,0));
                }else{
                    pq.add(new Node(nx,ny,diff));
                }
            }           
        }
              
        return answer;
    }
}