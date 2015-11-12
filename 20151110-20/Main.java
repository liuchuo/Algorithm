package test;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		for (int i = 1; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				System.out.println("" + i + j + j + i);
			}
		}
		in.close();
	}
}
