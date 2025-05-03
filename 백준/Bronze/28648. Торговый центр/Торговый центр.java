import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int total = 999999999;
		
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if(total > a + b) {
				total = a + b;
			}
		}
		
		System.out.println(total);
		sc.close();
	}
}