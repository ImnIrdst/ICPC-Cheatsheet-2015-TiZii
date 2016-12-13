import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Coded for https://www.hackerrank.com/challenges/computer-game
 */

public class Main {
    private static final boolean debug = true;
    private static final int INF = (int) 1e9;
    private static final double PI = 2 * Math.acos(0);
    private static final long MOD = 1000000007;


    public static class MCBM { // Max Cardinality Bipartite Matching, Using Alternating path Algorithm
        int n, m;
        int[] owner;
        boolean[] vis;
        ArrayList<Integer>[] adj;

        MCBM(int n, int m, ArrayList<Integer>[] adj) {
            this.n = n;
            this.m = m;
            this.adj = adj;
            this.vis = new boolean[n];
            this.owner = new int[n + m];
            Arrays.fill(this.owner, -1);
        }

        int run() {
            int mcbm = 0;
            for (int u = 0; u < n; u++) {
                Arrays.fill(vis, false);
                mcbm += alternatingPath(u);
            }
            return mcbm;
        }

        int alternatingPath(int u) {
            if (vis[u]) return 0;
            vis[u] = true;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u].get(i);
                if (owner[v] == -1 || alternatingPath(owner[v]) != 0) {
                    owner[v] = u;
                    return 1;
                }
            }
            return 0;
        }

        void printMatches(int[] a, int[] b) {
            for (int v = n; v < n + m; v++) {
                if (owner[v] == -1) continue;
                System.out.printf("v: %d, owner[v]: %d, (%d, %d)\n", v, owner[v], a[owner[v]], b[v - n]);
            }
        } // remove
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = n; // n + m = |V|

        int[] a = new int[n];
        int[] b = new int[m];
        Arrays.sort(a);
        Arrays.sort(b);

        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        for (int j = 0; j < m; j++) b[j] = sc.nextInt();

        ArrayList<Integer>[] adj = new ArrayList[n + m];
        for (int i = 0; i < n + m; i++) adj[i] = new ArrayList<>();

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (gcd(a[i], b[j]) != 1) adj[i].add(n + j);
            }
        }

        MCBM mcbm = new MCBM(n, m, adj);
        System.out.println(mcbm.run());
        mcbm.printMatches(a, b);
    }

    private static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
/*

 */
