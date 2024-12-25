package lgnd2016;

import java.util.Scanner;

/*
 * @author Hugo Paez https://github.com/HPaez
 */
public class C2 {

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        String[] matriz1 = null, matriz2 = null;
        String entrada, salida = "";
        int suma = 0;

        entrada = sc.nextLine();
        matriz1 = entrada.split("-1");

        for (int i = 0; i < matriz1.length; i++) {
            matriz2 = matriz1[i].split(" ");
            for (int j = 3; j < matriz2.length; j++) {
                if (Integer.parseInt(matriz2[j]) > 1) {
                    suma = suma + Integer.parseInt(matriz2[j]);
                    salida = salida.concat(" " + matriz2[j]);
                }
            }

            System.out.print(suma + "" + salida + ((i + 1 == matriz1.length) ? "" : " -1 "));
            suma = 0;
            salida = "";
        }

        System.out.println("");
    }
}
