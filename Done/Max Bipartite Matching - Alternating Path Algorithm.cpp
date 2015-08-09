#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adj; vi owner, vis; int n,b;

int altpath(int u){
	if(vis[u]) return 0; vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(owner[v]==-1 || altpath(owner[v])){
			owner[v]=u; return 1;
		}
	}
	return 0;
}

int main(){
	int tmp,tc,t=1; cin >> tc;
	while(tc--){
		cin >> n >> b; adj.assign(n+b,vi());
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<b ; j++){
				// if there is an edge from n group to b group
				cin >> tmp; if(tmp==1) adj[i].push_back(j+n);
			}
		}
		int ans=0; owner.assign(n+b,-1);
		for(int u=0 ; u<n ; u++){
			vis.assign(n,0); ans+=altpath(u);
		}
		printf("Case %d: a maximum of %d matched\n", t++, ans);
	}
	return 0;
}
