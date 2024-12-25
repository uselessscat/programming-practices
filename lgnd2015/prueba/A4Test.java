package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.A4;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class A4Test {

    static {
        System.out.println("Testing A4");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        A4.solution(new Scanner(testCase), new PrintWriter(output));
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

        String testCase = "37 289 87 927 77 143\n";
        String result = "FIN";

        testStringEquals(testCase, result);
    }

    @Test
    public void test2() {
        System.out.print("test 2");

        String testCase = "2 5 3 7 1 6 7 2 7 9 0 1 3 6 2 5 2 1 0 1 3 9 4 7";
        String result = "-12 -10 -8 -6 -4 -2 0 2 4 6";

        testStringEquals(testCase, result);
    }

    @Test
    public void test3() {

        System.out.print("test 3");

        String testCase = "1 3 5 7 7 9 3 1 9 11 3 7 5 5 1 15 13 17 19 1 3 5 7";
        String result = "FIN";

        testStringEquals(testCase, result);
    }

    @Test
    public void test4() {
        System.out.print("test 4");

        String testCase = "37 0 289 87 927 7 77 143 ";
        String result = "-18 -16 -14 -12 -10 -8 -6 -4 -2 0";

        testStringEquals(testCase, result);
    }
}
