//https://www.hackerrank.com/challenges/even-tree
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct edge{
	int u, v;
	edge(int u = 0, int v = 0):u(u), v(v){}
	edge rev(){ return edge(v, u); }
	bool operator<(const edge& op) const {
		return make_pair(u, v) < make_pair(op.u, op.v);
	}
	bool operator!=(const edge& op) const {
		return make_pair(u, v) != make_pair(op.u, op.v);
	}
	bool operator==(const edge& op) const {
		return make_pair(u, v) == make_pair(op.u, op.v);
	}
};

vector<int> vis; 
set<edge> st; edge notUse;

int bfs(int u){
	int ret = 0; vis[u] = 1;
	set<edge>::iterator it = st.lower_bound(edge(u, -1));
	for (it = it; it != st.end() && it->u == u; it++){
		if(!vis[it->v] && notUse!=*it) ret +=bfs(it->v);
	}
	return ret + 1;
}

int main(){
	
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v; u--, v--; 
		st.insert(edge(u, v)); st.insert(edge(v, u));
	}
	bool nothingsChanged = 0;
	while (!nothingsChanged){
		nothingsChanged = true;
		for (int u = 0; u < n; u++){
			vis.assign(n, 0); vector<edge> v;
			set<edge>::iterator it = st.lower_bound(edge(u, -1));
			for (it = it; it != st.end() && it->u == u; it++){
				notUse = *it; notUse = notUse.rev();
				
				int childs = bfs(it->v);
				if (childs % 2 == 0) v.push_back(*it);
			}
			for (int i = 0; i < v.size(); i++){
				if (st.count(v[i])) st.erase(v[i]), nothingsChanged = false;
				if (st.count(v[i].rev())) st.erase(v[i].rev()), nothingsChanged = false;
			}
		}
	}

	cout << (2 * m - st.size()) / 2 << endl;
}