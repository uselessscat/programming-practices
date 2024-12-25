package lgnd2015;

import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class A3 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        String r = sc.nextLine();
        String text = sc.nextLine();

        String r1 = r.substring(0, (r.length() - 1) / 2);
        String r2 = r.substring((r.length() - 1) / 2 + 1, r.length());

        String replacedtext = text;
        for (int i = 0, largo = r1.length(); i < largo; i++) {
            replacedtext = replacedtext.replace(r1.charAt(i), r2.charAt(i));
        }

        out.print(replacedtext);
        out.flush();
    }
}
