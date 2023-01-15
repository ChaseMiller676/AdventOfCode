import java.util.Scanner;
import java.io.File;

public class PartTwo {
    public static void main(String[] args) throws Exception {
	File input = new File("./input");
	Scanner fileScan = new Scanner(input);

	int currentCalories = 0;
	int[] topThreeCalories = {0, 0, 0};
	String fileLine;

	while (fileScan.hasNextLine()) {
	    fileLine = fileScan.nextLine();
	    if (fileLine.length() <= 0) {
		if (currentCalories > topThreeCalories[0]) {
		    topThreeCalories[0] = currentCalories;
		}
		if (currentCalories > topThreeCalories[1]) {
		    topThreeCalories[0] = topThreeCalories[1];
		    topThreeCalories[1] = currentCalories;
		}
		if (currentCalories > topThreeCalories[2]) {
		    topThreeCalories[1] = topThreeCalories[2];
		    topThreeCalories[2] = currentCalories;
		}

		currentCalories = 0;
		continue;
	}

		currentCalories += Integer.parseInt(fileLine);
	}

	int total = 0;
	for (int i = 0; i < 3; i++) {
	    System.out.printf("%d: %d\n", (i + 1), topThreeCalories[i]);
	    total += topThreeCalories[i];
	}

	System.out.printf("Total: %d\n", total);

	fileScan.close();
    }
}
