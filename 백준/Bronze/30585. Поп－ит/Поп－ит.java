import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		int count0 = 0, count1 = 0;
		
		for(int i = 0; i < n; i++) {
			String a = sc.next();
			for(int j = 0; j < a.length(); j++) {
				if(a.charAt(j) == '0') {
					count0++;
				}else if(a.charAt(j) == '1') {
					count1++;
				}
			}
		}
		
		if(count0 < count1) {
			System.out.println(count0);
		}else {
			System.out.println(count1);
		}
		sc.close();
	}
}