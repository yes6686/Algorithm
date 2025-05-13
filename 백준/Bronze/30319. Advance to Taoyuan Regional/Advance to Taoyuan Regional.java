import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		String a = sc.next();
		String[] b = a.split("-");
		
		int m = 0;
		if(b[1].charAt(0) == 0) {
			m += b[1].charAt(1) - 48;
		}else {
			m += (b[1].charAt(0) - 48) * 10;
			m += b[1].charAt(1) - 48;
		}
		
		int d = 0;
		if(b[2].charAt(0) == 0) {
			d += b[2].charAt(1) - 48;
		}else {
			d += (b[2].charAt(0) - 48) * 10;
			d += b[2].charAt(1) - 48;
		}
		
		if(m < 9 || m == 9 && d <= 16) {
			System.out.println("GOOD");
		}else {
			System.out.println("TOO LATE");
		}
		sc.close();
	}
}
