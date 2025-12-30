import java.util.*;

class Solution {
    
    private static List<Integer>[] adjList;
    private static boolean[] visited;
    
    private static void dfs(int x){
        if(visited[x]) return;
        visited[x] = true;
        
        for(int i=0;i<adjList[x].size();i++){
            dfs(adjList[x].get(i));
        }
    }
    
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        adjList = new ArrayList[n];
        visited = new boolean[n];
        
        for(int i=0;i<n;i++){
            adjList[i] = new ArrayList<>();
        }
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(computers[i][j]==1){
                    adjList[i].add(j);
                    adjList[j].add(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                answer++;
                dfs(i);
            }
        }
        
        
        
        
        return answer;
    }
}