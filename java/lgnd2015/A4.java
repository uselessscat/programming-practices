package lgnd2015;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class A4 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        String[] string = sc.nextLine().split("\\s+");

        LinkedList<Integer> topList = new LinkedList<>(
                Arrays.asList(0, -2, -4, -6, -8, -10, -12, -14, -16, -18));

        int pairs = 0;
        for (int i = 0, largo = string.length; i < largo; i++) {
            int parsedNumber = Integer.parseInt(string[i]);

            if (parsedNumber % 2 == 0) {
                pairs++;

                for (int e = 0; e < topList.size(); e++) {
                    if (parsedNumber == topList.get(e)) {
                        break;
                    } else if (parsedNumber > topList.get(e)) {
                        topList.add(e, parsedNumber);
                        topList.removeLast();
                        break;
                    }
                }
            }
        }

        if (pairs == 0) {
            out.print("FIN");
            out.flush();
        } else {
            StringBuilder str = new StringBuilder();

            for (int i = topList.size() - 1; i >= 0; i--) {
                str.append(topList.get(i)).append(" ");
            }

            out.print(str.toString().trim());
            out.flush();
        }
    }
}
