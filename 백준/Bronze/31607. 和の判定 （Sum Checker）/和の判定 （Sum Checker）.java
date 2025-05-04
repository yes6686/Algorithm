import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		if(a + b == c || a + c == b || b + c == a) {
			System.out.println("1");
		}else {
			System.out.println("0");
		}
		sc.close();
	}
}