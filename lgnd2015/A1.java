package lgnd2015;

import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * @author Uselessscat
 */
public class A1 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        int count = -1;
        long sum = 0;

        do {
            try {
                count = sc.nextInt();
            } catch (InputMismatchException e) {
                sc.next();
            }
        } while (count < 1);

        while (count != 0) {
            try {
                sum += sc.nextInt(2);
                count--;
            } catch (InputMismatchException e) {
                sc.next();
            }
        }

        out.print(sum);
        out.flush();
    }
}
