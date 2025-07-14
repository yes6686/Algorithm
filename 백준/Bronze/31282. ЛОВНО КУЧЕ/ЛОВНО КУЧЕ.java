import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		
		if(n % (k - m) == 0) {
			System.out.println(n / (k - m));
		}else if(n % (k - m) != 0) {
			System.out.println(n / (k - m) + 1);
		}
		sc.close();
	}
}