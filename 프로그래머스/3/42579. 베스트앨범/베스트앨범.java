import java.util.*;

class Solution {
    
    class Song{
        int index;
        int play;
        
        Song(int index, int play){
            this.index = index;
            this.play =play;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
      
        HashMap<String, Integer> hm = new HashMap<>();
        HashMap<String, List<Song>> gs = new HashMap<>();
        
        for(int i=0;i<genres.length;i++){
            hm.put(genres[i], hm.getOrDefault(genres[i],0)+plays[i]);
            if(!gs.containsKey(genres[i])){
                gs.put(genres[i],new ArrayList<>());
            }
            gs.get(genres[i]).add(new Song(i, plays[i]));
        }
    
        List<String> gorder = new ArrayList<>(gs.keySet());
        gorder.sort((a,b) -> hm.get(b) - hm.get(a));
    
        List<Integer> result = new ArrayList<>();
        
        for(String genre : gorder){
            List<Song> list = gs.get(genre);
            
            list.sort((a,b)->{
                if(a.play != b.play){
                    return b.play - a.play;
                }
                return a.index - b.index;
            });
            
            for(int i=0;i<list.size() && i<2;i++){
                result.add(list.get(i).index);
            }
            
        }
        
        
        
        
        
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}