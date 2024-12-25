package lgnd2015;

import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Uselessscat
 */
public class B2 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        int cant = Integer.parseInt(sc.nextLine().trim());
        String[] words = new String[cant];

        for (int i = 0; i < cant; i++) {
            words[i] = sc.nextLine().trim();
        }

        String text = sc.nextLine().trim();
        int count = 0;
        for (String word : words) {
            int lastIndex = 0;

            while (true) {
                lastIndex = text.indexOf(word, lastIndex);

                if (lastIndex != -1) {
                    count++;
                    lastIndex = Math.min(lastIndex + 1, text.length());
                } else {
                    break;
                }
            }

        }

        out.print(count);
        out.flush();
    }
}
