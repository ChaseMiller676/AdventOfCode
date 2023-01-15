import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.io.File;

public class PartOne {
    static HashMap<Character, Integer> myRef
	= new HashMap<>(Map.of(
			       'X', 1,
			       'Y', 2,
			       'Z', 3
			       ));

    static Map<Character, Integer> opponentRef
	= new HashMap<>(Map.of(
			'A', 1,
			'B', 2,
			'C', 3
		        ));

    static int calculatePoints(char playerMove, char elfMove) {
	switch(playerMove) {
	case 'X':
	    switch(elfMove) {
	    case 'A': return 4;
	    case 'B': return 1;
	    case 'C': return 7;
	    }
	    break;
	case 'Y':
	    switch(elfMove) {
	    case 'A': return 8;
	    case 'B': return 5;
	    case 'C': return 2;
	    }
	    break;
	case 'Z':
	    switch(elfMove) {
	    case 'A': return 3;
	    case 'B': return 9;
	    case 'C': return 6;
	    }
	    break;
	}

	return -1;
    }


    public static void main(String[] args) throws Exception {
	Scanner fileScan = new Scanner(new File("./input"));
	String line;
	char opponentMove, myMove;
	int score = 0, lineCount = 1;

	while (fileScan.hasNextLine()) {
	    line = fileScan.nextLine();
	    opponentMove = line.charAt(0);
	    myMove = line.charAt(2);

	    score += calculatePoints(myMove, opponentMove);/*myRef.get(myMove) > opponentRef.get(opponentMove)
		? 6 + myRef.get(myMove)
		: (myRef.get(myMove) == opponentRef.get(opponentMove)
		? 3 + myRef.get(myMove)
		: myRef.get(myMove));*/
	    System.out.printf("Line %d\n", lineCount);
	    lineCount++;
	}

	System.out.printf("Final Score: %d\n", score);

	fileScan.close();
    }
}
