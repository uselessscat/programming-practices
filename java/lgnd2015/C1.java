package lgnd2015;

import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class C1 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        String abc = "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ";

        String text = sc.nextLine();
        int adv = sc.nextInt();

        String generated = "";

        for (int i = 0, largo = text.length(); i < largo; i++) {
            int idx = abc.indexOf(text.charAt(i));

            if (idx + adv >= abc.length() || idx + adv < 0) {
                idx = idx + (adv % abc.length());
            } else {
                idx = idx + adv;
            }

            generated += abc.charAt(idx) + "";
        }

        out.println(generated);
        out.flush();
    }
}
