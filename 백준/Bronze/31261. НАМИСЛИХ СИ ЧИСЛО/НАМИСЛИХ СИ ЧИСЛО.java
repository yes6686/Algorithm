import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		b = b + a;
		b = b * a;
		b = b + a;
		b = b * a;
		System.out.println(b);
		sc.close();
	}
}