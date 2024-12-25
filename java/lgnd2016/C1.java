package lgnd2016;

import java.util.Scanner;

/*
 * @author Hugo Paez https://github.com/HPaez
 */
public class C1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int entrada, j = 0;
        int[] vector = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 71, 73, 79, 83, 89, 97};

        terminar:
        while (true) {
            entrada = Integer.parseInt(sc.nextLine());

            for (int i = 0; i < vector.length; i++) {
                if (vector[i] == entrada) {
                    System.out.println("Hay " + i + " primos menores que mi primo");
                    break terminar;
                } else {
                    continue;
                }
            }
        }
    }
}
