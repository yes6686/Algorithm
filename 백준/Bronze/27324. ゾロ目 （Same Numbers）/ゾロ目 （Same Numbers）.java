import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(n / 10 == n % 10) {
			System.out.println("1");
		}else {
			System.out.println("0");
		}
	}
}