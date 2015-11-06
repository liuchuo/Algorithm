package test;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		System.out.print("Input a positive integer, it must less than 1000: ");
		int price = in.nextInt();
		in.close();
		
		int low = 0, mid = 500, high = 1000;
		do{
			if(mid > price){
				
				System.out.print(mid + "->");
				high = mid;
				mid = (low + high) / 2;
				
			} else if( mid < price){
				System.out.print(mid + "->");
				low = mid;
				mid = (high + low) / 2;
			}
		} while(mid != price);
		
		System.out.println(mid);
	}
}
