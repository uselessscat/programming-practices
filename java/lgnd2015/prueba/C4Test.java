package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.C4;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class C4Test {

    static {
        System.out.println("Testing C4");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        C4.solution(new Scanner(testCase), new PrintWriter(output));
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

        String testCase
                = "220 284\n"
                + "12 24\n"
                + "30 567\n"
                + "1184 1210\n"
                + "-1";
        String result
                = "SON NUMEROS AMIGOS\r\n"
                + "FALLO\r\n"
                + "FALLO\r\n"
                + "SON NUMEROS AMIGOS\r\n";

        testStringEquals(testCase, result);
    }
}
