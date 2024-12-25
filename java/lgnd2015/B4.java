package lgnd2015;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class B4 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        int[][] matrix = new int[sc.nextInt()][sc.nextInt()];
        for (int[] matrix1 : matrix) {
            for (int e = 0; e < matrix.length; e++) {
                matrix1[e] = sc.nextInt();
            }
        }

        int[] array = new int[sc.nextInt()];
        for (int i = 0; i < array.length; i++) {
            array[i] = sc.nextInt();
        }

        int enc = -1;
        for (int i = 0; i < matrix.length; i++) {
            if (Arrays.equals(matrix[i], array)) {
                enc = i;
                break;
            }
        }

        if (enc > -1) {
            out.println("FILA " + enc);
            out.flush();
            return;
        }

        for (int i = 0; i < matrix[0].length; i++) {
            boolean a = true;
            for (int e = 0; e < matrix.length || e < array.length; e++) {
                if (matrix[e][i] != array[e]) {
                    a = false;
                }
            }
            if (a == true) {
                enc = i;
                break;
            }
        }

        if (enc > -1) {
            out.println("COLUMNA " + enc);
            out.flush();
        }
    }
}
