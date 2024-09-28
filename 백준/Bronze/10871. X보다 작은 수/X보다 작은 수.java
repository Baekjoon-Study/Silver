import java.util.Scanner; 

public class Main {
	public static void main(String[] args) {	
		Scanner scanner = new Scanner(System.in);
		int N, X;
		N = scanner.nextInt();
		int array [] = new int [N];
		X = scanner.nextInt();
		
		for (int i = 0; i < N; i++) {
			array[i] = scanner.nextInt();
		}
		
		
		for (int i = 0; i < N; i++) {
			if (array[i] < X) {
				System.out.print(array[i] + " ");
			}
		}

		scanner.close();
	}
}