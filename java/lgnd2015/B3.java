package lgnd2015;

import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;

/**
 * @author Uselessscat
 */
public class B3 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        String[] instrucciones = sc.nextLine().split("\\s+");
        String[] numeros = sc.nextLine().split("\\s+");

        Stack<Integer> st = new Stack<>();

        for (int i = 0, largo = instrucciones.length; i < largo; i++) {
            int num = Integer.parseInt(numeros[i]);
            switch (instrucciones[largo - i - 1].trim()) {
                case "L":
                    st.push(num);
                    break;
                case "N":
                    break;
                case "E":
                    st.push(num + 2);
                    break;
                case "I":
                    st.push(num - 1);
                    break;
            }
        }

        String outString = "";
        for (int i = 0, largo = st.size(); i < largo; i++) {
            outString += st.pop() + " ";
        }

        out.println(outString.trim());
        out.flush();
    }
}
