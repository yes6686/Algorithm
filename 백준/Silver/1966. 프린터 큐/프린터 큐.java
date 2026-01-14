import java.util.*;

public class Main {

    public static class Node{
        int val;
        int idx;
        public Node(int val, int idx){
            this.val = val;
            this.idx = idx;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for(int i=0;i<T;i++){
            int n = sc.nextInt();
            int m = sc.nextInt();
            Queue<Node> queue = new ArrayDeque<>();
            Queue<Node> pq = new PriorityQueue<>((a,b)->Integer.compare(b.val,a.val));

            for(int j=0;j<n;j++){
                int x = sc.nextInt();
                queue.add(new Node(x,j));
                pq.add(new Node(x,j));
            }

            int cnt = 1;
            while(!queue.isEmpty()){
                Node curr = queue.poll();
                if(curr.idx == m && pq.peek().val == curr.val){
                    System.out.println(cnt);
                    break;
                }else if(pq.peek().val == curr.val){
                    pq.poll();
                    cnt++;
                }else{
                    queue.add(curr);
                }
            }
        }
    }
}