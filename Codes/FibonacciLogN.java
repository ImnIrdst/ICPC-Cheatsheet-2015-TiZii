package CheatSheet;

/**
 * Created by iman on 1/26/16.
 * Calculates fibonacci in O(log n);
 */
public class FibonacciLogN {
	public static int m = 13;


	static long[] fb = new long[90];
	public static long f(int n){
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (fb[n] != 0) return fb[n];
		return (f(n-1) + f(n-2))%m;
	}

	public static long fib(int n) {
		int i = 1, h = 1;
		int j = 0, k = 0;
		while (n > 0) {
			if (n % 2 == 1) {
				int t = (j * h)%m;
				j = (((i * h)%m) + ((j * k)%m) + t)%m;
				i = (((i * k)%m) + t)%m;
			}
			int t = (h * h)%m;
			h = ((2 * k * h)%m + t)%m;
			k = ((k * k)%m + t)%m;
			n = n / 2;
		}
		return j;
	}

	public static void main(String[] args) {
		for (int i = 0 ; i < 20 ; i++){
			System.out.print(fib(i) + " ");

		}
		System.out.println();
		for (int i=0 ; i<20 ; i++){
			System.out.print(f(i) + " ");
		}
	}
}
