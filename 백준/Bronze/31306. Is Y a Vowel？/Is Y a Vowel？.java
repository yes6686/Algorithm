import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] s = br.readLine().toCharArray();

        int vowelCount = 0;
        int yCount = 0;

        for (int i = 0; i < s.length; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowelCount++;
            }
            if (s[i] == 'y') {
                yCount++;
            }
        }

        System.out.println(vowelCount +" "+ (vowelCount+yCount));
    }
}