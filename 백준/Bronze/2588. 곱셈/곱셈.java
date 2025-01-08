import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int one = scanner.nextInt();
        int two = scanner.nextInt();
        int three = one*(two%10);
        int four = one*(two%100-two%10);
        int five = one*(two%1000-two%100);
        int six = three+four+five;
        System.out.println(three);
        System.out.println(four/10);
        System.out.println(five/100);
        System.out.println(six);
    }
}
