import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
        
		for(int i = 0; i < n; i++) {
			String a = sc.next();
			if(a.equals("Algorithm")) {
				System.out.println("204");
			}
            else if(a.equals("DataAnalysis")) {
				System.out.println("207");
			}
            else if(a.equals("ArtificialIntelligence")) {
				System.out.println("302");
			}
            else if(a.equals("CyberSecurity")) {
				System.out.println("B101");
			}
            else if(a.equals("Network")) {
				System.out.println("303");
			}
            else if(a.equals("Startup")) {
				System.out.println("501");
			}
            else if(a.equals("TestStrategy")) {
				System.out.println("105");
			}
		}
	}
}