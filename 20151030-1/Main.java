package test;

public class Main {

	public static void main(String[] args) {
		
		//算
		for(int i = 2; i <= 9; i++){
			//法
			for(int j = 0; j <= 9; j++){
				//描
				for(int k = 0; k <= 9; k++){
					//述
					for(int l = 0; l <= 9; l++){
						//题
						for(int m = 2; m <= 8; m++){
							if((i * 10000 + j * 1000 + k * 100 + l * 10 + m) * i == m * 100000 + m * 10000 + m * 1000 + m * 100 + m * 10 + m){
								System.out.println("算: " + i);
								System.out.println("法: " + j);
								System.out.println("描: " + k);
								System.out.println("述: " + l);
								System.out.println("题: " + m);
							}
						}
					}
				}
			}
		}
	}
}
