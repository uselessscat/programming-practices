package lgnd2016;

import java.util.ArrayList;
import java.util.Scanner;

/*
 * @author Hugo Paez https://github.com/HPaez
 */
public class B4 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        ArrayList<String> vector = new ArrayList();
        String[][] cadena;
        String entrada;
        String delimitador = " ";
        int cont = 0;
        while (true) {
            entrada = sc.nextLine();
            if (entrada.equals("END")) {
                break;
            }
            vector.add(entrada);
        }
        for (int i = 0; i < vector.size(); i++) {
            String[] texto = vector.get(i).split(" ");
            if (texto[0].equals("ADD")) {
                String[] hora1 = texto[1].split(":");
                String[] hora2 = texto[2].split(":");
                int segundos1, segundos2, suma, horas, minutos, segundos;
                segundos1 = (((Integer.parseInt(hora1[0]) * 60) * 60) + (Integer.parseInt(hora1[1]) * 60) + Integer.parseInt(hora1[2]));
                segundos2 = (((Integer.parseInt(hora2[0]) * 60) * 60) + (Integer.parseInt(hora2[1]) * 60) + Integer.parseInt(hora2[2]));
                suma = segundos1 + segundos2;
                horas = suma / 3600;
                minutos = (suma - (3600 * horas)) / 60;
                segundos = suma - ((horas * 3600) + (minutos * 60));
                System.out.println(((horas < 10) ? "0" : "") + horas + ":" + ((minutos < 10) ? "0" : "") + minutos + ":" + ((segundos < 10) ? "0" : "") + segundos);
            } else {
                String[] hora1 = texto[1].split(":");
                String[] hora2 = texto[2].split(":");
                int segundos1, segundos2, suma, horas, minutos, segundos;
                segundos1 = (((Integer.parseInt(hora1[0]) * 60) * 60) + (Integer.parseInt(hora1[1]) * 60) + Integer.parseInt(hora1[2]));
                segundos2 = (((Integer.parseInt(hora2[0]) * 60) * 60) + (Integer.parseInt(hora2[1]) * 60) + Integer.parseInt(hora2[2]));
                suma = segundos1 - segundos2;
                horas = suma / 3600;
                minutos = (suma - (3600 * horas)) / 60;
                segundos = suma - ((horas * 3600) + (minutos * 60));
                System.out.println(((horas < 10) ? "0" : "") + horas + ":" + ((minutos < 10) ? "0" : "") + minutos + ":" + ((segundos < 10) ? "0" : "") + segundos);
            }
        }
    }
}
