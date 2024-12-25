package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.A2;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class A2Test {

    static {
        System.out.println("Testing A2");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        A2.solution(new Scanner(testCase), new PrintWriter(output));
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

        String testCase = "5 7 86 81 52 20 71 46 25 9 8 2 63 4 0";
        String result = "Mandan los impares 261";

        testStringEquals(testCase, result);
    }

    @Test
    public void test2() {
        System.out.print("test 2");

        String testCase = "100 86 82 20 26 43 43 33 10 8 26 63 49 0";
        String result = "Mandan los pares 358";

        testStringEquals(testCase, result);
    }

    @Test
    public void test3() {
        System.out.print("test 3");

        String testCase = "27 33 44 16 0";
        String result = "Nadie manda";

        testStringEquals(testCase, result);
    }

    @Test
    public void test4() {
        System.out.print("test 4");

        String testCase = "61 37 55 69 49 15 71 17 51 93 65 97 21 83 59 75"
                + " 53 87 41 63 77 07 25 73 01 29 47 35 85 03 81 33 31 67"
                + " 79 89 91 19 39 45 43 11 13 99 57 23 95 05 27 09 48 54"
                + " 56 92 60 30 26 02 24 70 40 50 90 88 08 28 72 66 16 04"
                + " 14 06 20 12 58 74 84 52 32 82 94 44 86 64 34 46 36 76"
                + " 96 78 68 62 22 38 42 50 50 80 10 98 18";
        String result = "Mandan los pares 2550";

        testStringEquals(testCase, result);
    }
}
