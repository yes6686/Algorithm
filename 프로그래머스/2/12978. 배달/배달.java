import java.util.*;

class Solution {
    
    public static class Node{
        int x, cost;
        public Node(int x, int cost){
            this.x = x;
            this.cost = cost;
        }
    }
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        
        List<Node>[] adjList = new ArrayList[N+1];
        int[] dist = new int[N+1];
        
        for(int i=1;i<=N;i++){
            adjList[i] = new ArrayList<>();
            dist[i] = Integer.MAX_VALUE;
        }
        
        for(int[] edge : road){
            adjList[edge[0]].add(new Node(edge[1],edge[2]));
            adjList[edge[1]].add(new Node(edge[0],edge[2]));
        }
        
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) ->
                                    Integer.compare(a.cost, b.cost));
        pq.add(new Node(1,0));
        dist[1] = 0;

        while(!pq.isEmpty()){
            Node curr = pq.poll();
            if(curr.cost > dist[curr.x]) continue;
            answer++;
            
            for(Node next : adjList[curr.x]){
                if(dist[next.x] > curr.cost + next.cost 
                   && K >= curr.cost + next.cost ){
                    dist[next.x] = curr.cost + next.cost;
                    pq.add(new Node(next.x, dist[next.x]));
                }
            }
        }

        return answer;
    }
}