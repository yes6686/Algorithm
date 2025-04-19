import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int []a = new int[3];
		int []b = new int[3];
		int team1 = 0;
		int team2 = 0;
		
		for(int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt();
		}
		
		for(int i = 0; i < b.length; i++) {
			b[i] = sc.nextInt();
		}
		
		for(int i = 0; i < 3; i++) {
			team1 += a[i] * (i + 1);
			team2 += b[i] * (i + 1);
		}
		
		if(team1 > team2) {
			System.out.println("1");
		}else if(team1 < team2) {
			System.out.println("2");
		}else {
			System.out.println("0");
		}
		
		sc.close();
	}
}