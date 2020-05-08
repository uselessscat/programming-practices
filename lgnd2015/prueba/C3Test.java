package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.C3;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class C3Test {

    static {
        System.out.println("Testing C3");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        C3.solution(new Scanner(testCase), new PrintWriter(output));
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
                = "2015/09/30\n"
                + "2015/01/12\n"
                + "2015/03/03\n"
                + "null";
        String result
                = "MIERCOLES\r\n"
                + "LUNES\r\n"
                + "MARTES\r\n";

        testStringEquals(testCase, result);
    }
}
