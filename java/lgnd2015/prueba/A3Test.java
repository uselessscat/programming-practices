package lgnd2015.prueba;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Scanner;
import lgnd2015.A3;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Uselessscat
 */
public class A3Test {

    static {
        System.out.println("Testing A3");
    }

    public void testStringEquals(String testCase, String result) {
        StringWriter output = new StringWriter();
        A3.solution(new Scanner(testCase), new PrintWriter(output));
        try {
            assertEquals(output.toString(), result);
            System.out.println(" - Test OK.");
        } catch (AssertionError e) {
            System.out.println(" - FAILED!.");
            throw e;
        }
    }

    @Test
    public void test1() {
        System.out.print("test 1");

        String testCase = "anplu AmhLU\nla señora maria llego a la puerta";
        String result = "LA señorA mAriA LLego A LA hUertA";

        testStringEquals(testCase, result);
    }

    @Test
    public void test2() {
        System.out.print("test 2");

        String testCase = "aeiou AEIOU\nLa vaca come pasto y camina por el campo.";
        String result = "LA vAcA cOmE pAstO y cAmInA pOr El cAmpO.";

        testStringEquals(testCase, result);
    }

    @Test
    public void test3() {
        System.out.print("test 3");

        String testCase = "MIQSAONZERHDC tinatsgroelms\nRCAR SHNEZIADE RC NRQISH";
        String result = "este algoritmo es genial";

        testStringEquals(testCase, result);
    }
}
