import java.util.Scanner;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger a = sc.nextBigInteger();
		while(a.compareTo(BigInteger.valueOf(0)) != 0) {
			if(a.remainder(BigInteger.valueOf(42)).compareTo(BigInteger.valueOf(0)) == 0) {
				System.out.println("PREMIADO");
			}else {
				System.out.println("TENTE NOVAMENTE");
			}
			a = sc.nextBigInteger();
		}
	}
}