#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

typedef vector<int> vi;

struct DisJointSet {
	vi par, rnk, cnt; int numOfSets;

	DisJointSet(int n = 0){
		par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1); //par==parent
		numOfSets=n; // if we wanna count number of disjoint sets
	}

	int find(int a){
		int i=a,j=a,tmp;
		while(par[i]!=-1){ i=par[i]; }
		while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
		return i;
	}
	int uni(int a, int b){
		int A=find(a),B=find(b);
		if(A!=B){
			if(rnk[A]<rnk[B]) swap(A,B); // union using rank
			if(rnk[A]==rnk[B]) rnk[A]++;
			par[B]=A;
			cnt[A]+=cnt[B]; // if we wanna count each set size
			numOfSets--; // if we wanna count number of disjoint sets
		}
		return cnt[A]; // if we wanna count each set size
	}
};

struct Edge { int u, v, w;
	Edge(int u=0, int v=0, int w=0):u(u), v(v), w(w){}
	bool operator<(const Edge& b) const { return w < b.w; } 
	string toString(){ 
		stringstream sstr;
		sstr << u << "," << v << "," << w;
		string str; sstr >> str;
		return str;	
	} //remove
};

typedef vector<Edge> ve;

struct Kruskal {
	ve edges; vi marked; DisJointSet st; 
	Kruskal(int n, ve& edges):edges(edges) { st = DisJointSet(n); }
	int run(){ int result; sort(edges.begin(), edges.end());
		for (int i=0 ; i<edges.size() ; i++) { Edge e = edges[i];
			if (st.find(e.u) != st.find(e.v)) {
				st.uni(e.u, e.v); result += e.w; marked.push_back(i);
			}
		}
		return result;
	}

	void printSelectedEdges(){
		cout << "MST edges:" << endl;
		for(int i=0 ; i<marked.size() ; i++) {
			Edge e = edges[marked[i]];
			cout << e.toString() << endl;
		}
	} // remove
};

int main() {
	int n, m;
	cin >> n >> m;

	ve edges;
	for(int i=0 ; i<m ; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(Edge(u, v, w));
	}

	for(int i=0 ; i<edges.size() ; i++) {
		cout << edges[i].toString() << endl;
	}

	Kruskal kruskal(n, edges);
	cout << kruskal.run() << endl;
	kruskal.printSelectedEdges();
}


/*
IN:
5 6
1 3 5
4 5 0
2 1 3
3 2 1
4 3 4
4 2 2

OUT:
4,5,0
3,2,1
4,2,2
2,1,3

*/