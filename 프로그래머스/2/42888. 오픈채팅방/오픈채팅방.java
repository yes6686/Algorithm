import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        
        // (유저 아이디, in/out/change)
        Queue<String> queue = new ArrayDeque<>(); 
        
         // (유저 아이디, 유저 이름)
        HashMap<String, String> hm = new HashMap<>();
        
        // 고유아이디 in/out 
        // enter => 1 , leave =>2 , change =>3
        
        for(int i=0;i<record.length;i++){
            String[] parts = record[i].split(" ");
            if(parts[0].equals("Enter")){
                queue.add(parts[1]+" in");
                hm.put(parts[1],parts[2]);
            }else if(parts[0].equals("Leave")){
                queue.add(parts[1]+" out");
            }else if(parts[0].equals("Change")){
                hm.put(parts[1],parts[2]);
            }
        }
        
        List<String> arr = new ArrayList<>();
        
        while(!queue.isEmpty()){
            String[] parts = queue.poll().split(" ");
            String ui = parts[0];
            if(parts[1].equals("in")){
                arr.add(hm.get(ui)+"님이 들어왔습니다.");
            }else if(parts[1].equals("out")){
                arr.add(hm.get(ui)+"님이 나갔습니다.");
                
            }
        }
        
        
        // 고유아이디 이름
        
        return arr.stream().toArray(String[]::new);
    }
}