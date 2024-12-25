package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.B3;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class B3Test {

    static {
        System.out.println("Testing B3");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        B3.solution(new Scanner(testCase), new PrintWriter(output));
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

        String testCase = "L L L N N E I I L E N N L L\n"
                + "1 2 0 4 5 6 7 8 9 10 5 12 13 14\n";

        // estupido retorno de linea
        String result = "14 13 12 11 7 6 6 7 2 1\r\n";

        testStringEquals(testCase, result);
    }
}
