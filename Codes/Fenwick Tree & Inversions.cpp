// vector (vi), iostream, algo, 
#define LSOne(i) (i & (-i))
struct FenwickTree {
	vi ft; FenwickTree() {}
	FenwickTree(int n) { ft.assign(n + 1, 0); } // init n + 1 zeroes
	int rsq(int b) { // returns RSQ(1, b), pass b >= 1
		int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}
	int rsq(int a, int b) { // returns RSQ(a, b)
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void update(int k, int v) { // note: n = ft.size() - 1
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

// get largest value with cumulative sum less than or equal to x;
// for smallest, pass x-1 and add 1 to result
int getind(int x) {// ***Change Needed***
  int idx = 0, mask = TREE_SIZE; //(must be a power of 2)
  while(mask && idx < TREE_SIZE) {
    int t = idx + mask;
    if(x >= tree[t]) {idx = t; x -= tree[t]; }
    mask >>= 1;
  }
  return idx;
}

int main(){
	while(cin >> n){ // count inversions, (Change Needed)
		a.assign(n,0); b.assign(n,0); tree.assign(n,0);
		for(int i=0 ; i<n; i++){
			cin >> a[i]; b[i]=a[i];
		}
		sort(b.begin(),b.end());
		for(int i=0 ; i<n ; i++){
			int rank=(int)(lower_bound(b.begin(),b.end(),a[i])-b.begin());
			a[i]=rank+1;
		}
		int64 invs=0;//num of inversions
		for(int i=n-1 ; i>=0 ; i--){
			invs+=read(a[i]-1);
			update(a[i],1);
		}
		cout << invs << endl;
	}
}
