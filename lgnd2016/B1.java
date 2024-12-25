package lgnd2016;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class B1 {

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String[] asignaturasnotas = line.split("-1");

        ArrayList<Integer> asignaturas = new ArrayList<>();

        for (int i = 0, length = asignaturasnotas.length; i < length; i++) {
            String[] notas = asignaturasnotas[i].trim().split(" ");

            float sumanota = 0f;
            for (int e = 0, elength = notas.length; e < elength; e += 2) {
                int nota = Integer.parseInt(notas[e]);
                int exig = Integer.parseInt(notas[e + 1]);
                sumanota += (float) (nota * exig) / 100;
            }

            asignaturas.add((int) sumanota);
        }

        Object[] notasFin = asignaturas.toArray();
        float promFinal = 0f;
        for (int i = 0, length = notasFin.length; i < length; i++) {
            System.out.print(notasFin[i] + " ");
            promFinal += (int) notasFin[i];
        }
        System.out.println((int) (promFinal / notasFin.length));
    }
}
