package lgnd2016;

import java.util.ArrayList;
import java.util.Scanner;

/*
 * @author Hugo Paez https://github.com/HPaez
 */
public class A5 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> vector = new ArrayList();
        String[][] cadena;
        int contador = 0;
        for (int i = 0; i < 100; i++) {
            vector.add(sc.nextLine());
        }
        cadena = new String[vector.size()][];
        for (int i = 0; i < vector.size(); i++) {
            cadena[i] = vector.get(i).split(" ");
            if (cadena[i][0].equals("JAVIER") || cadena[i][1].equals("JAVIER")) {
                contador++;
            }
        }
        System.out.println("Existe(n) " + (vector.size() - contador) + " persona(s) de la lista que no se llaman Javier");
    }
}
