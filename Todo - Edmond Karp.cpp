#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef vector< int > vi;
typedef vector< vi  > vii;

const int MAX = 100+10;
const int INF = 1e9;

int res[MAX][MAX],mf,f,s,t,n,m,par[MAX]; vii adj; vi dist;

void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

int main(){
	int tc=1;
	while(cin >> n && n){
		memset(res,0,sizeof res); 
		mf=0; adj.assign(n,vi());
		cin >> s >> t >> m; s--; t--;
		int u,v,c;
		while(m--){
			cin >> u >> v >> c; u--; v--;
			res[u][v]+=c; res[v][u]+=c;
			adj[u].push_back(v); adj[v].push_back(u);
		}
		while(1){
			f=0; memset(par,-1,sizeof par); dist.assign(n,INF);
			dist[s]=0; queue<int> q; q.push(s);
			while(!q.empty()){
				int u=q.front(); q.pop();
				if(u==t) break;
				for(int i=0 ; i<adj[u].size(); i++){
					int v=adj[u][i];
					if(res[u][v]>0 && dist[v]==INF){
						dist[v]=dist[u]+1; q.push(v); par[v]=u;
					}
				}
			}
			agument(t,INF);
			if(f==0) break;
			mf+=f;
		}
		printf("Network %d\n", tc++);
		printf("The bandwidth is %d.\n\n", mf);
	}
	return 0;}
