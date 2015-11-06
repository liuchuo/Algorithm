package test;

import java.util.Stack;

public class Main {

	public static void main(String[] args) {

		char[] operator = { '+', '-', '*', '/' };

		for (char c1 : operator) {
			for (char c2 : operator) {
				for (char c3 : operator) {
					for (char c4 : operator) {
						// 5 c1 5 c2 5 c3 5 c4 5 = 5
						if(isMatcher("" + 5 + c1 + 5 + c2 + 5 + c3 + 5 + c4 + 5)){
							System.out.println(" 5 " + c1 + " 5 " + c2 + " 5 "  + c3 + " 5 " + c4 + " 5 ");
						}
					}
				}
			}
		}
	}

	public static boolean isMatcher(String s) {
		
		//use stack
		Stack<String> c = new Stack<String>();
		for(int i = 0; i < s.length(); i++){
			if(s.charAt(i) == '*' || s.charAt(i) == '/'){
				int num1 = Integer.parseInt("" + c.pop());
				char op = s.charAt(i++);
				int num2 = Integer.parseInt("" + s.charAt(i));
				
				switch (op) {
				case '*':
					c.push("" + (num1 * num2));
					break;

				case '/':
					c.push("" + (num1 / num2));
					break;
				}
			} else if((s.charAt(i) >= '0' && s.charAt(i) <= '9') || s.charAt(i) == '+' || s.charAt(i) == '-'){
				c.push("" + s.charAt(i));
			}
		}
		
		int result = Integer.parseInt(c.get(0));
		if(c.size() > 1){
			for (int i = 1; i < c.size() - 1; i+=2) {
				switch (c.get(i).toCharArray()[0]) {
				case '+':
					result += Integer.parseInt(c.get(i + 1));
					break;
				case '-':
					result -= Integer.parseInt(c.get(i + 1));
					break;
				}
			}
		}
		return result == 5;
	}
}
