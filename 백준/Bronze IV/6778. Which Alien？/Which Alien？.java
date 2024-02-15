import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n,m;
		n = scanner.nextInt();
		m= scanner.nextInt();
		if(n>=3 && m<=4) {
			System.out.println("TroyMartian");
		}
		if(n<=6 && m>=2) {
			System.out.println("VladSaturnian");
		}
		if(n<=2 && m<=3) {
			System.out.println("GraemeMercurian");
		}
	}	
}