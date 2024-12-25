package lgnd2016;

import java.util.Scanner;

/*
 * @author Hugo Paez https://github.com/HPaez
 */
public class D3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int texto1 = sc.nextInt();
        int texto2 = sc.nextInt();
        int resta = texto2 - texto1;

        int[] billetes = {20000, 10000, 5000, 2000, 1000, 500, 100, 50, 10, 5, 1};
        int[] cantbilletes = new int[billetes.length];

        System.out.println("El vuelto es: " + resta);
        for (int j = 0; j < billetes.length; j++) {
            cantbilletes[j] = resta / billetes[j];
            resta = resta % billetes[j];
        }

        for (int i = 0; i < cantbilletes.length; i++) {
            if (cantbilletes[i] != 0) {
                if (i <= 4) {
                    System.out.println(cantbilletes[i] + " Billete(s) de " + billetes[i]);
                } else {
                    System.out.println(cantbilletes[i] + " Moneda(s) de " + billetes[i]);
                }
            }
        }

    }

}
