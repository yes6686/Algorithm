import java.util.*;

public class Main {
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       int N = scan.nextInt();
       scan.nextLine();
       String channel;
       Vector<String> vector = new Vector<>();
       
       for(int i = 0; i<N; i++) {
          channel = scan.nextLine();
          vector.add(channel);
       }
          for(int i = 0; i < N; i++) {
           
             if(vector.get(i).equals("KBS1")) {
                vector.remove(i);
                vector.add(0, "KBS1");
                for(int j = 0; j<i; j++) {   
                   System.out.print("4"); 
                }
                break;
                
             }

             System.out.print("1");
          }
          
          
          for(int i = 0; i<N; i++) {
             if(vector.get(i).equals("KBS2")) {
                vector.remove(i);
                vector.add(1, "KBS2");
                for(int j = 0; j<i-1; j++) {
                   System.out.print("4"); 
                }
                break; 
             }
             System.out.print("1");
          } 
       scan.close();
   
    }
}