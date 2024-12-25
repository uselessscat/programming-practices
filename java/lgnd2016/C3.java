package lgnd2016;

import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class C3 {

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int[] x = new int[5];
        int[] y = new int[5];

        int lado = 10;
        for (int i = 0, lenght = lado * lado; i < lenght; i++) {
            int index = Integer.parseInt(sc.nextLine());

            if (index > 0) {
                x[index - 1] = i / lado;
                y[index - 1] = i % lado;
            }
        }

        String result = "";
        for (int i = 0; i < x.length; i++) {
            result += "(" + x[i] + "," + y[i] + ") ";
        }

        System.out.println(result.trim());
    }
}
