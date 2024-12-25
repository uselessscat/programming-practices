package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.D1;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class D1Test {

    static {
        System.out.println("Testing D1");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        D1.solution(new Scanner(testCase), new PrintWriter(output));
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
                = "16 14 5 10 13 19 21 18 8 22 24 2 25 3 15 1 6 4 17 7 9 11 20 10 12 23";
        String result
                = "1 2 3 4 5\r\n"
                + "16 17 18 19 6\r\n"
                + "15 24 25 20 7\r\n"
                + "14 23 22 21 8\r\n"
                + "13 12 11 10 9\r\n";

        testStringEquals(testCase, result);
    }
}
