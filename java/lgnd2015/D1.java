package lgnd2015;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author Uselessscat
 */
public class D1 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        int[] dato = new int[25];
        int[][] matr = new int[5][5];

        for (int i = 0; i < dato.length; i++) {
            dato[i] = sc.nextInt();
        }

        Arrays.sort(dato);

        // una forma dificil de imprimir un espiral!
        try {
            for (int i = 0, size = dato.length, dir = 0, ste = 0, mst = 4, m2 = 1, x = 0, y = 0;
                    i < size;
                    i++, ste++) {

                if (ste == mst) {
                    ste = 0;
                    dir++;
                    m2++;

                    if (dir > 3) {
                        dir = 0;
                    }

                    if (m2 > 1) {
                        m2 = 0;
                        mst--;
                    }
                }

                matr[y][x] = dato[i];

                switch (dir) {
                    case 0:
                        x++;
                        break;
                    case 1:
                        y++;
                        break;
                    case 2:
                        x--;
                        break;
                    case 3:
                        y--;
                        break;
                }
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("AIOOBE");
        }

        for (int i = 0; i < matr.length; i++) {
            for (int e = 0; e < matr[i].length; e++) {
                out.print(matr[i][e] + " ");
            }
            out.print("\n");
            out.flush();
        }
    }

    /*if (cont > 1) {
                cont = 0;
                limit--;
            }

            if (adv == limit) {
                adv = 0;
                dir++;
                cont++;
            }

            if (dir > 3) {
                dir = 0;
            }

     */
}
