package lgnd2015;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class C4 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        ArrayList<Boolean> arr = new ArrayList<>();

        while (true) {
            int num1 = sc.nextInt();
            if (num1 == -1) {
                break;
            }

            int num2 = sc.nextInt();

            // num1
            int maxD = (int) Math.sqrt(num1);
            int sum = 1;
            for (int i = 2; i <= maxD; i++) {
                if (num1 % i == 0) {
                    sum += i;
                    int d = num1 / i;
                    if (d != i) {
                        sum += d;
                    }
                }
            }

            // num2
            int maxD2 = (int) Math.sqrt(num2);
            int sum2 = 1;
            for (int i = 2; i <= maxD2; i++) {
                if (num2 % i == 0) {
                    sum2 += i;
                    int d = num2 / i;
                    if (d != i) {
                        sum2 += d;
                    }
                }
            }

            arr.add(sum == num2 && sum2 == num1);
        }

        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i)) {
                out.println("SON NUMEROS AMIGOS");
            } else {
                out.println("FALLO");
            }
            out.flush();
        }
    }

}
