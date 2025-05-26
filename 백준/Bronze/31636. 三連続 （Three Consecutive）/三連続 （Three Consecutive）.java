import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);		
		
		int n = sc.nextInt();
		String s = sc.next();
		int count = 0;
		int flag = 0;
		
		for(int i = 0; i < n - 2; i++) {
			if(s.charAt(i) == 'o' && s.charAt(i + 1) == 'o' && s.charAt(i + 2) == 'o') {
				flag = 1;
			}
		}
		
		if(flag == 1) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}