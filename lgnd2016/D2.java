package lgnd2016;

import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class D2 {

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        String line = sc.nextLine().trim();
        String texto = sc.nextLine().trim();

        switch (line) {
            case "NO":
                for (int i = 0; i < texto.length(); i++) {
                    System.out.println(getSpace(i) + texto.charAt(texto.length() - i - 1) + getSpace(texto.length() - i - 1));
                }
                break;
            case "SO":
                for (int i = 0; i < texto.length(); i++) {
                    System.out.println(getSpace(texto.length() - i - 1) + texto.charAt(i) + getSpace(i));
                }
                break;
            case "N":
                for (int i = 0; i < texto.length(); i++) {
                    System.out.println(texto.charAt(texto.length() - 1 - i));
                }
                break;
            case "S":
                for (int i = 0; i < texto.length(); i++) {
                    System.out.println(texto.charAt(i));
                }
                break;
        }

    }

    static String getSpace(int count) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < count; i++) {
            sb.append(" ");
        }

        return sb.toString();
    }
}
