import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		
		if(a <= b && b <= c || c <= b && b <= a) {
			System.out.println(b);
		}else if(a <= c && c <= b || b <= c && c <= a) {
			System.out.println(c);
		}else {
			System.out.println(a);
		}
		
		sc.close();
	}
}