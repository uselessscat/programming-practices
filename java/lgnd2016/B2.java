package lgnd2016;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class B2 {

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        ArrayList<String> palabras = new ArrayList<>();
        ArrayList<String> palabrasIngles = new ArrayList<>();

        while (true) {
            String line = sc.nextLine();
            if (line.equals("FIN")) {
                break;
            }
            String[] pal = line.split(" ");

            palabras.add(pal[0]);
            palabrasIngles.add(pal[1]);
        }

        while (true) {
            String line = sc.nextLine();
            if (line.equals("FIN")) {
                break;
            }
            String[] pal = line.split(" ");

            StringBuilder sb = new StringBuilder();
            boolean esta = true;
            palabras:
            for (int i = 0, length = pal.length; i < length; i++) {

                for (int j = 0, jlength = palabras.size(); j < jlength; j++) {
                    if (pal[i].trim().equals(palabras.get(j))) {
                        sb.append(palabrasIngles.get(j));
                        sb.append(" ");
                        continue palabras;
                    }
                }
                esta = false;
            }
            String resul = sb.toString();
            if (!esta) {
                System.out.println("ERROR");
            } else {
                System.out.println(resul.trim());
            }
        }

        System.out.println("LISTO");
    }
}
