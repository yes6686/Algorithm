import java.util.Stack;
import java.util.StringTokenizer;
import java.util.Scanner;
public class Main {
	private static final String OP = "+-*/()=";
	public static int priorityOperator(String token) {
		switch (token) {
		case "(":
		case ")":
			return 0;
		case "+":
		case "-":
			return 1;
		case "*":
		case "/":
			return 2;
		default:
			return -1;
		}
	}
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String string = scanner.next();
		StringTokenizer st = new StringTokenizer(string, OP, true);
		String tokens[] = new String[st.countTokens()];

		for (int i = 0; st.hasMoreTokens(); i++) {
			String k = st.nextToken();
			tokens[i] = k;
		}
		Stack<String> stringStack = new Stack<String>();
		String postfixTokens[] = new String[tokens.length];
		int postfixPos = 0; int tokenPos = 0;
		while (tokenPos != tokens.length) {
			String token = tokens[tokenPos];
			if (OP.indexOf(token) < 0) {
				postfixTokens[postfixPos] = token;
				postfixPos+=1;
			} else {
				int priority = priorityOperator(token);
				if (priority == 0) {
					if (token.equals("(")) {
						stringStack.push(token);
					} else {
						while (!stringStack.isEmpty()) {
							String pop = stringStack.pop();
							if (pop.equals("(")) {
								break;
							}
							postfixTokens[postfixPos++] = pop;
						}
					}
				} else {
					while (!stringStack.isEmpty()) {
						int peekPriority = priorityOperator(stringStack.peek());
						if (peekPriority < priority) {
							break;
						}
						postfixTokens[postfixPos] = stringStack.pop();
						postfixPos+=1;
					}
					stringStack.push(token);
				}
			}
			tokenPos+=1;
		}

		while (!stringStack.isEmpty()) {
			postfixTokens[postfixPos] = stringStack.pop();
			postfixPos+=1;
		}
		for (int i = 0; i < postfixPos; i++) {
			System.out.print(postfixTokens[i]);
		}
	
	}
}