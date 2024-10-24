import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		int n = sc.nextInt();
		int[] c = new int [n];
		
		for(int i = 0; i < c.length; i++) {
			c[i] = sc.nextInt();
		}
		
		for(int i = 0; i < c.length; i++) {
			int money = 0;
			if(c[i] <= 1000) {
				money = c[i] * a;
			}else if(c[i] > 1000) {
				money = 1000 * a + (c[i] - 1000) * b;
			}
			System.out.println(c[i] + " " + money);
		}
		sc.close();
	}
}