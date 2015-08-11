struct DisJointSet{
	vector<int> par,rnk,cnt; int numOfsets;

	DisJointSet(int n){
		par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1); //par==parent
		numOfsets=n; // if we wanna count number of disjoint sets
	}

	int Find(int a){
		int i=a,j=a,tmp;
		while(par[i]!=-1){ i=par[i]; }
		while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
		return i;
	}
	int Uni(int a, int b){
		int A=Find(a),B=Find(b);
		if(A!=B){
			if(rnk[A]<rnk[B]) swap(A,B); // union using rank
			if(rnk[A]==rnk[B]) rnk[A]++;
			par[B]=A;
			cnt[A]+=cnt[B]; // if we wanna count each set size
			numOfsets--; // if we wanna count number of disjoint sets
		}
		return cnt[A]; // if we wanna count each set size
	}
};

struct edge{ int u, v, w;
	edge(int u=0, int v=0, int w=0):u(u), v(v), w(w){};
	bool operator<(const edge& b) const {
		if(w == b.w && v == b.w) return u < b.u;
		if(w == b.w ) return v < b.v; return w < b.w;
	}
};

int n, m, bit; vector<edge> e; vi marked;

int Kruskal(){
	DisJointSet djst(n); marked.clear();
	sort(e.begin(), e.end()); int ans=0; int j=0;
	for(int i=0; i<e.size() && j<n-1 ; i++){
		if(djst.Find(e[i].u) != djst.Find(e[i].v)){
			djst.Uni(e[i].u, e[i].v); ans+=e[i].w; j++; marked.push_back(i);
		}
	}
	return ans;}
