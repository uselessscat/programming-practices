package lgnd2016;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class A4 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<String> cifrado = new ArrayList<>();
        ArrayList<String> descifrado = new ArrayList<>();

        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            if ("FIN".equals(line)) {
                break;
            }
            cifrado.add(line);
        }

        for (int i = 0, length = cifrado.size(); i < length; i++) {
            String linea = cifrado.get(i);
            int firstspaceindex = linea.indexOf(" ");
            int offset = Integer.parseInt(linea.substring(0, firstspaceindex));
            String frase = linea.substring(firstspaceindex + 1);

            StringBuilder sb = new StringBuilder();
            for (int e = 0, elength = frase.length(); e < elength; e++) {
                char result = frase.charAt(e);
                if (result != ' ') {
                    result = (char) (frase.charAt(e) + offset);

                    if (result > 'Z') {
                        result = (char) (result - ('Z' - 'A' + 1));
                    }
                }
                sb.append(result);
            }

            descifrado.add(sb.toString());
        }

        for (int i = 0; i < descifrado.size(); i++) {
            System.out.println(descifrado.get(i));
        }
    }
}
