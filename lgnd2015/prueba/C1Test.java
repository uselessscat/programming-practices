package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.C1;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class C1Test {

    static {
        System.out.println("Testing C1");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        C1.solution(new Scanner(testCase), new PrintWriter(output));
        try {
            assertEquals(result, output.toString());
            System.out.println(" - Test OK.");
        } catch (AssertionError e) {
            System.out.println(" - FAILED!.");
            throw e;
        }
    }

    @Test
    public void test1() {
        System.out.print("test 1");

        String testCase = "Losgeniosnoduermen\n1";
        String result = "Mpthfojptopevfsnfo\r\n";

        testStringEquals(testCase, result);
    }

    @Test
    public void test2() {
        System.out.print("test 2");

        String testCase = "Losgeniosnoduermen\n2";

        /* La siguiente linea es exactemente igual al ejemplo 2 del problema,
        Sin embargo en el inicio da la lista de "únicos caracteres válidos", y
        la letra "w" no es parte de ellas. O el ejemplo o el listado está 
        mal.
                             Aqui!   V
        String result = "Nquigpkqupqfwgtogp\r\n"; */
        String result = "Nquigpkqupqfxgtogp\r\n";

        testStringEquals(testCase, result);
    }
}
