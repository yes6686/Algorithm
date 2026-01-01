import java.util.*;

class Solution {
    public String[] solution(String[] strings, int n) {
        String[] answer = {};
        
        Arrays.sort(strings, (o1,o2)-> 
                    o1.charAt(n)==o2.charAt(n) ? 
                    o1.compareTo(o2) : 
                    Character.compare(o1.charAt(n), o2.charAt(n)));
        
        return strings;
    }
}