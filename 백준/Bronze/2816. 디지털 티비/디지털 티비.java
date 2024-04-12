import java.util.*;

public class Main {
    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       int N = scan.nextInt();
       scan.nextLine();
       String channel;
   	int kbs1Location=0; // KBS1 위치
   	int kbs2Location=0; // KBS2 위치
       for(int i = 0; i<N; i++) {
          channel = scan.nextLine();
          if (channel.equals("KBS1")) {
  			kbs1Location = i;
  		}
  		if (channel.equals("KBS2")) {
  			kbs2Location = i;
  		}
       }
       for (int i = 0; i < kbs1Location; i++) {
   			System.out.print(1);
   	}
   	for (int i = 0; i < kbs1Location; i++) {
			System.out.print(4);
   	}
   	if (kbs1Location > kbs2Location) {
   		kbs2Location += 1;
   	}
   	for (int i = 0; i < kbs2Location; i++) {
			System.out.print(1);
   	}
   	for (int i = 0; i < kbs2Location - 1; i++) {
			System.out.print(4);
   	}
    }
}
