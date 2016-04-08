// Doesn't run properly

vvi adjOrg, adjRev;  vi vis, ord, col;

void dfsOrg(int u){
	if (vis[u]) return; vis[u] = true;
	for (int i = 0; i < adjOrg[u].size(); i++){
		dfsOrg(adjOrg[u][i]);
	}
	ord.push_back(u);
}

int dfsRev(int u, int color){
	if (col[u]) return 0; col[u] = color;

	int ret = 1;
	for (int i = 0; i < adjRev[u].size(); i++){
		ret += dfsRev(adjRev[u][i], color);
	}
	return ret;
}

int main(){
	while (cin >> n && n){
		int u, v; string line;
		adjOrg.assign(n, vi());
		adjRev.assign(n, vi());

		for (int i = 0; i < n; i++){
			stringstream sstr(line);
			sstr >> u;
			while (sstr >> v){
				adjOrg[u].push_back(v);
				adjRev[v].push_back(u);
			}
		}

		ord.clear();
		vis.assign(n, 0);
		for (int u = 0; u < n; u++){
			if (!vis[u]) dfsOrg(u);
		}
		int color = 1;
		col.assign(n, 0);
		while (!ord.empty()){
			int u = ord.back();
			if (!col[u]){
				int size = dfsRev(u, color); // SCC Size
				if (size > 1){
					for (int v = 0; v < n; v++){
						if (col[v] == color) //inSame SCC;
							;
					}
				}
				color++;
			}
			ord.pop_back();
		}
	}
}