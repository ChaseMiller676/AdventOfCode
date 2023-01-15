import java.util.Scanner;
import java.io.File;

public class PartOne {
    public static void main(String[] args) throws Exception {
	File input = new File("./input");
	Scanner fileScan = new Scanner(input);

	int mostCalories = 0, currentCalories = 0;
	String fileLine;

	while (fileScan.hasNextLine()) {
	    fileLine = fileScan.nextLine();
	    if (fileLine.length() <= 0) {
		if (mostCalories < currentCalories) {
			mostCalories = currentCalories;
		}
		currentCalories = 0;
		continue;
	    }

		currentCalories += Integer.parseInt(fileLine);
	}

	System.out.printf("Most Calories: %d\n", mostCalories);

	fileScan.close();
    }

    
}
