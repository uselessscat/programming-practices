package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.A1;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class A1Test {

    static {
        System.out.println("Testing A1");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        A1.solution(new Scanner(testCase), new PrintWriter(output));
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

        String testCase = "10 00101101 11100100 10000101 10111100 00010111"
                + " 11010100 11111001 00110101 10111111 00111101";
        String result = "1383";

        testStringEquals(testCase, result);
    }

    @Test
    public void test2() {
        System.out.print("test 2");

        String testCase = "12 11010111111 1001 11001000110 1011111 11000"
                + " 101000 1001000 11011 1 10 110010 11001000";
        String result = "3853";

        testStringEquals(testCase, result);
    }

    @Test
    public void test3() {
        System.out.print("test 3");

        String testCase = "100 01 101 11111 100100 10110 11010111"
                + " 11001110000 10000 101 11010 11001 10100 1010 111110"
                + " 1110011 111001 11100 1011100 1 100 1101001110 1110010"
                + " 1100 1100 11101110000 101000 10011 11 111 1100 100001"
                + " 11110011101 10111110 1010 10110001011 1011 100110 11"
                + " 100100 10101101100 100111 1100000 10010101 10110111"
                + " 100111 11101 110 11 11 1011010101 100111110 10111001"
                + " 11000 111100010 1110011 110011 1001101101 11010100010"
                + " 110101000 111100 11 10011 11 11011 111001 110101"
                + " 1001 1111 11001011001 11101 11111 110 100 1101001100"
                + " 101100001 110 1110010 1 101111 11000 1001100 101101"
                + " 10101 11110110101 1011111 1111 1000 1010 101010 1010100"
                + " 1 1000011111 10110001 111010011 1110010 1110110111"
                + " 11000111 111100 11001001 1001";
        String result = "24076";

        testStringEquals(testCase, result);
    }
}
