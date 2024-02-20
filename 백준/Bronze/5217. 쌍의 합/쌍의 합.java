import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		for(int i=0;i<n;i++) {
			int k = scanner.nextInt();
			System.out.print("Pairs for "+k+":");
			for(int j=1;j<=k;j++) {
				int a = j;
				int b =k-j;
				if(a>=b) break;
				if(j==1) {
					System.out.print(" "+a+" "+b);
				}else {
					System.out.print(", "+a+" "+b);
					
				}
			}
			System.out.println();
		}
	}	
}
