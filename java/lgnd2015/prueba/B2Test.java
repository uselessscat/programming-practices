package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.B2;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class B2Test {

    static {
        System.out.println("Testing B2");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        B2.solution(new Scanner(testCase), new PrintWriter(output));
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

        String testCase = "4\nCasa\nPerro\nGato\nHola\n"
                + "El Perro de mi Casa Tiene un gato en su Casa";
        String result = "3";

        testStringEquals(testCase, result);
    }

    @Test
    public void test2() {
        System.out.print("test 2");

        String testCase = "5\na\na\na\na\na\n"
                + "aaaaa";
        String result = "25";

        testStringEquals(testCase, result);
    }
}
