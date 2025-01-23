import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int r = sc.nextInt();
		int g = sc.nextInt();
		int b = sc.nextInt();
		int c = r * 3 + g * 4 + b * 5;
		
		System.out.println(c);
		sc.close();
	}
}