package lgnd2015;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Scanner;

/**
 *
 * @author Uselessscat
 */
public class C3 {

    public static void main(String[] args) {
        solution(new Scanner(System.in), new PrintWriter(System.out));
    }

    public static void solution(Scanner sc, PrintWriter out) {
        ArrayList<String> list = new ArrayList<>();

        while (true) {
            String t = sc.nextLine();
            if ("null".equals(t)) {
                break;
            } else {
                list.add(t.trim());
            }
        }

        String[] days = {"nothing", "DOMINGO", "LUNES", "MARTES", "MIERCOLES",
            "JUEVES", "VIERNES", "SABADO"};
        for (int i = 0, largo = list.size(); i < largo; i++) {
            String[] date = list.get(i).split("/");

            // definitivamente esto no funciona como quiero!!!
            Calendar c = Calendar.getInstance();
            c.set(Integer.parseInt(date[0]),
                    Integer.parseInt(date[1]),
                    Integer.parseInt(date[2]));

            out.println(days[c.get(Calendar.DAY_OF_WEEK)]);
            out.flush();
        }
    }
}
