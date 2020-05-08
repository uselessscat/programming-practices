package lgnd2016;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class C4 {

    public static void main(String[] args) throws java.lang.Exception {
        // no funcional
        int[][] piramide = new int[10][19];

        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < piramide.length; i++) {
            String linea = sc.nextLine().trim();

            for (int j = 0; j < piramide[i].length; j++) {
                switch (linea.charAt(j)) {
                    case 'X':
                        piramide[i][j] = -1;
                        break;
                    case '0':
                        piramide[i][j] = 0;
                        break;
                    case '1':
                        piramide[i][j] = 1;
                        break;
                    case 'T':
                        piramide[i][j] = 2;
                        break;
                }
            }
        }

        System.out.println(Arrays.deepToString(piramide));

        boolean encuentrenATutankamon = false;
        int x = 0, y = piramide.length - 1, dir = +1;

        while (!encuentrenATutankamon) {
            if (x + dir <= piramide[y].length) {
                switch (piramide[y][x + dir]) {
                    case 1:
                        System.out.print("(" + y + "," + x + ") ");
                        x += dir;
                        break;
                    case 0:
                        System.out.println("(" + y + "," + x + ")");
                        y--;
                        if (piramide[y][x + dir] == 0) {
                            dir = dir * -1;
                        }
                        break;
                    case 2:
                        encuentrenATutankamon = true;
                }
            } else {
                // 
                break;
            }
        }
    }
}
