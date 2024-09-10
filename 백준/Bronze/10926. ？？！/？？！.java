import java.util.Scanner;

public class Main{
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String string = scanner.nextLine();
		string = string + "??!";
		System.out.println(string);
		scanner.close();
	}
}