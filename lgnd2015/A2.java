package lgnd2015;

import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Uselessscat
 */
public class A2 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        int sumapar = 0, sumimpar = 0;

        while (sc.hasNextInt()) {
            int read = sc.nextInt();
            if (read == 0) {
                break;
            }

            if (read % 2 == 0) {
                sumapar += read;
            } else {
                sumimpar += read;
            }
        }

        // pair = mandan los pares, odd = mandan los impares, equal = nadie manda
        if (sumapar == sumimpar) {
            out.print("Nadie manda");
        } else {
            out.print("Mandan los " + ((sumapar > sumimpar)
                    ? "pares " + sumapar
                    : "impares " + sumimpar));
        }

        out.flush();
    }
}
