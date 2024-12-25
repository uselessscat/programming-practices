package lgnd2016;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class D1 {

    public static void main(String[] args) throws java.lang.Exception {
        // BOCETO NO FUNCIONAL
        Scanner sc = new Scanner(System.in);

        String[] str = sc.nextLine().trim().split(" ");

        int fila = Integer.parseInt(str[0]), col = Integer.parseInt(str[1]);
        int filas = Integer.parseInt(str[2]), columnas = Integer.parseInt(str[3]);

        int[] x = new int[9], y = new int[9];
        int coord = 0;

        for (int i = 4, length = 4 + (filas * columnas); i < length; i++) {
            int parse = Integer.parseInt(str[i]);
            if (parse > 0) {
                y[parse - 1] = (i - 4) / filas;
                x[parse - 1] = (i - 4) % columnas;
                coord++;
            }
        }

        System.out.println(Arrays.toString(x));
        System.out.println(Arrays.toString(y));

        for (int i = 0, cx = col, cy = fila; i < coord; i++) {
            if (cx < x[i]) {
                while (cx < x[i]) {
                    cx++;
                    System.out.print("E");
                }
            } else if (cx > x[i]) {
                while (cx > x[i]) {
                    cx--;
                    System.out.print("O");
                }
            }

            if (cy < y[i]) {
                while (cy < y[i]) {
                    cy++;
                    System.out.print("S");
                }
            } else if (cy < y[i]) {
                while (cy < y[i]) {
                    cy--;
                    System.out.print("N");
                }
            }
        }

        System.out.println("");
    }
}
