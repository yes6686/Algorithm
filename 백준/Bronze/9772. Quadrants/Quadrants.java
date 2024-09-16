import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			double a = sc.nextDouble();
			double b = sc.nextDouble();
			if(a > 0 && b > 0) {
				System.out.println("Q1");
			}else if(a < 0 && b > 0) {
				System.out.println("Q2");
			}else if(a < 0 && b < 0) {
				System.out.println("Q3");
			}else if(a > 0 && b < 0) {
				System.out.println("Q4");
			}else if(a == 0 || b == 0) {
				System.out.println("AXIS");
			}
		}
	}
}