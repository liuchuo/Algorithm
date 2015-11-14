package test;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		boolean isOutput = false;
		
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					for (int l = 0; l <= 9; l++) {
						for (int m = 0; m <= 9; m++) {
							for (int p = 0; p <= 9; p++) {
								if (i + j + k + l + m + p == n) {
									if (i == 0 && j != 0 && j == p && k == m) {
										System.out.println("" + j + k + l + m + p);
										isOutput = true;
									} else if (i != 0 && i == p && j == m && k == l){
										System.out.println("" + i + j + k + l + m + p);
										isOutput = true;
									}
								}
							}
						}
					}
				}
			}
		}
		if (isOutput == false) {
			System.out.println("-1");
		}
		in.close();
	}
}