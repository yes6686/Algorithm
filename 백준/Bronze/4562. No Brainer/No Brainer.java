import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n;
		n = scanner.nextInt();
		for(int i=1;i<=n;i++) {
			int a,b;
			a=scanner.nextInt();
			b=scanner.nextInt();
			if(a<b) {
				System.out.println("NO BRAINS");
			}else {
				System.out.println("MMM BRAINS");			
			}
		}
	}	
}
