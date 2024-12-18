import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int u = sc.nextInt();
		int l = sc.nextInt();
		
		if(n >= 1000) {
			if(u >= 8000 || l >= 260) {
				System.out.println("Very Good");
			}else {
				System.out.println("Good");
			}
		}else {
			System.out.println("Bad");
		}
		sc.close();
	}
}