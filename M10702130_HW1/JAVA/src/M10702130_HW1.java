import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class M10702130_HW1 {

	public static void main(String[] args) {
		try {
			int start, end, ans, guess;
			
			Scanner keyIn  = new Scanner(System.in);
			Scanner fileIn = new Scanner(new FileReader("input.txt"));
			
			start = fileIn.nextInt();
			end   = fileIn.nextInt();
			ans   = fileIn.nextInt();
			
			while (true) {
				System.out.println("Please guess an integer number between " + start + " and " + end);
				
				guess = keyIn.nextInt();
				
				if (guess <= start || guess >= end) {
					System.out.println("The number you entered is not within the valid range.");
					System.out.println("Please try again!\n");
				} else if (guess < ans) {
					start = guess;
				} else if (guess > ans) {
					end = guess;
				} else {
					System.out.println("Bingo! You hit the bomb.");
					break;
				}
			}
			
			keyIn.close();
			fileIn.close();
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
