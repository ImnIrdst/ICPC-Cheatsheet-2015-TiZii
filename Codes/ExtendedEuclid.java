import java.util.Scanner;

/**
 * Created by iman on 11/26/16.
 */
public class Main {
    public static class ExtendedEuclid {
        public static int x0;
        public static int y0;
        public static int c;
        public static int d;

        public static int gcd(int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }

        public static void calculate(int a, int b) {
            if (b == 0) {
                x0 = 1;
                y0 = 0;
                d = a;
                return;
            }
            calculate(b, a % b);

            int x1 = y0;
            int y1 = x0 - (a / b) * y0;

            x0 = x1;
            y0 = y1;
        }


        public static int howManyPositiveSolutions(int a, int b, int c) {
            if (c % gcd(a, b) != 0) return 0; // no solution even negatives

            x0 *= c / gcd(a, b);
            y0 *= c / gcd(a, b); // x = x0 + (b/d)n, y = y0 - (a/d)n
            double lowerBoundForN = (double) (-x0 + 0.5) / (b / d); // for x>0
            double upperBoundForN = (double) (+y0 - 0.5) / (a / d); // for y>0
            return (int) Math.max(0, Math.ceil(upperBoundForN) - Math.floor(lowerBoundForN) - 1); // how many int between
        }

    }

    public static void main(String[] args) {
        ExtendedEuclid.calculate(25, 18); // Copetitive Programming 2 Example
    }

}
