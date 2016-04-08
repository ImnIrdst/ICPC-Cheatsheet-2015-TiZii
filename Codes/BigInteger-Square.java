import java.math.BigInteger;
import java.util.Scanner;
//import java.util.

public class Main {
    // https://en.wikipedia.org/wiki/Integer_square_root
    public static BigInteger sqrt(BigInteger n) {
        BigInteger cur = null; // X(k)
        BigInteger nxt = n; // X(k+1)
        while(true) {
            cur = nxt;
            nxt = cur.add(n.divide(cur)).divide(BigInteger.valueOf(2));
            if(nxt.equals(cur)) break;
        }
        if(cur.multiply(cur).equals(n)) return cur;
        else return null;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = Integer.parseInt(sc.nextLine());
        while(tc-- > 0) {
            sc.nextLine();
            BigInteger y = new BigInteger(sc.nextLine());
            if(y.equals(BigInteger.ZERO)) System.out.println(0);
            else                          System.out.println(sqrt(y));
            if(tc>0) System.out.println();
        }
    }
}
