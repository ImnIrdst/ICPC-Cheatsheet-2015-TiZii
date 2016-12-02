package CheatSheet;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by iman on 1/27/16.
 */
public class PrimeNumbers {
	public static class PrimeNumberUtils {
		long MAX;
		boolean[] isp;
		ArrayList<Integer> primes;

		public PrimeNumberUtils(long MAX) {
			this.MAX = MAX;
			this.isp = new boolean[(int)MAX];
			this.primes = new ArrayList<Integer>();
		}

		public void genPrimes(){
			Arrays.fill(isp, true);
			isp[0] = isp[1] = false;
			for(long i=2 ; i<MAX; i++){
				if(isp[(int)i]){ primes.add((int)i);
					for(long j=i*i ; j<MAX ; j+=i) isp[(int)j] = false;
				}
			}
		}

		boolean isPrime(int n){
			if(n < MAX) return isp[n];
			for(int i=0 ; i<primes.size() && primes.get(i) * primes.get(i) <=n ; i++){
				if(n % primes.get(i) ==0) return false;
			}
			return true;
		}

		long divisors, coPrimes;
		public ArrayList<Integer> factors, powers;
		public void factorsUtils(int n){
			coPrimes = n; // coPrimes =  all m (m<n && gcd(m,n)==1) = euler Phi function
			divisors = 1; // divisors  =  all m (m<n && gcd(m,n)==m) = (n%m == 0)
			factors = new ArrayList<>();
			powers  = new ArrayList<>();

			long tmp=n;
			for(int i=0, pf=2 ; pf*pf<=n; i++, pf = primes.get(i)){
				int pow=0;
				while(tmp%pf==0){
					tmp/=pf; pow++;
				}
				if(pow > 0) {
					factors.add(pf); powers.add(pow);
					coPrimes -= coPrimes/pf; divisors *= (pow+1);
				}
			}
			if(tmp>1) {
				coPrimes -= coPrimes / tmp; divisors *= (1 + 1);
			}
		}
	}

	public static void main(String[] args){

	}
}
