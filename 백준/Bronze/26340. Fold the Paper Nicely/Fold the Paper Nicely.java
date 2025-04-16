import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			System.out.println("Data set: " + a + " " + b + " " + c);
			
			for(int j = 1; j <= c; j++) {
				if(a >= b) {
					a = a / 2;
				}else if(a < b) {
					b = b / 2;
				}
			}
			
			if(a > b) {
				System.out.println(a + " " + b);
			}else {
				System.out.println(b + " " + a);
			}
			System.out.println();
		}
		sc.close();
	}
}