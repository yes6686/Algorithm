import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int test = sc.nextInt();
		int a[][] = new int[3][test];
		
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < test; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		
		int judge = 0;
		for(int i = 0; i < 3; i++) {
			judge = 0;
			for(int j = 0; j < test; j++) {
				if(a[i][j] == 7) {
					judge = 1;
					break;
				}
			}
			
			if(judge == 0)
				break;
		}
		
		if(judge == 0)
			System.out.println("0");
		else
			System.out.println("777");
		sc.close();
	}
}