#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e8;



struct ToNode{
	int v, w;
	ToNode(int v, int w)
		:v(v), w(w){}
};

struct QEntry{
	int node, cost;
	QEntry(int node, int cost)
		:node(node), cost(cost){}
	bool operator<(const QEntry& op) const {
		return cost < op.cost;
	}
};

typedef vector<int>     vi;
typedef vector<ToNode> vtn;
typedef vector<vtn   > vvtn;

int n, m; vvtn adj;

int dijkstra(int s, int t, vi& dist){
	dist.assign(n, INF);
	priority_queue<QEntry> q;
	q.push(QEntry(s, 0)); dist[s] = 0;

	while (!q.empty()){
		QEntry u = q.top(); q.pop();
		if (u.node == t) return u.cost;
		if (u.cost > dist[u.node]) continue;
		for (int i = 0; i < adj[u.node].size(); i++){
			QEntry v(adj[u.node][i].v, u.cost + adj[u.node][i].w);
			if (dist[v.node] > v.cost){
				dist[v.node] = v.cost; q.push(v);
			}
		}
	}
	return INF;
}
