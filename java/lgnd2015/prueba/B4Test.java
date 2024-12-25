package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.B4;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class B4Test {

    static {
        System.out.println("Testing B4");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        B4.solution(new Scanner(testCase), new PrintWriter(output));
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

        String testCase = "2 2 1 2 3 4 2 3 4";
        String result = "FILA 1\r\n";

        testStringEquals(testCase, result);
    }

    @Test
    public void test2() {
        System.out.print("test 2");

        String testCase = "3 3 3 4 5 6 7 8 9 0 1 3 6 7 8";
        String result = "FILA 1\r\n";

        testStringEquals(testCase, result);
    }

    @Test
    public void test3() {
        System.out.print("test 3");

        String testCase = "3 3 3 4 5 6 7 8 9 0 1 3 5 8 1";
        String result = "COLUMNA 2\r\n";

        testStringEquals(testCase, result);
    }
}
