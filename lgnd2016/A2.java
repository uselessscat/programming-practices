package lgnd2016;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class A2 {

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        String input = sc.nextLine();

        int conjuntos = 0;
        ArrayList<String> subconjuntos = new ArrayList();

        for (int i = 0, in = 0, fin = 0, length = input.length(); i < length; i++) {
            switch (input.charAt(i)) {
                case '{':
                    in = i + 1;
                    conjuntos++;
                    break;
                case '}':
                    fin = i;
                    subconjuntos.add(input.substring(in, fin));
                    break;
            }
        }

        System.out.print(conjuntos);
        for (int i = 0, length = subconjuntos.size(); i < length; i++) {
            String[] splits = subconjuntos.get(i).split(",");

            if (splits.length == 1) {
                if (splits[0].length() == 0) {
                    System.out.print(" " + 0);
                    continue;
                }
            }
            System.out.print(" " + splits.length);
        }

        System.out.println();
    }
}
