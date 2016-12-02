import java.util.*;

public class Solution {
    static int[] dist;
    static ArrayList<Link>[] graph;
    static final int INF = (int)1e6;

    public static class Link {
        public int v, w;
        public Link(int v, int w) {
            this.v = v;
            this.w = w;
        }
    }

    public static class QEntry {
        public int u, cost;
        
        public QEntry(int u, int cost) {
            this.u = u;
            this.cost = cost;
        }
    }


    private static int dijkstra(int s, int t) {
        Arrays.fill(dist, INF);
        PriorityQueue<QEntry> q = new PriorityQueue<>(10, new Comparator<QEntry>() {
            @Override
            public int compare(QEntry o1, QEntry o2) {
                return Integer.compare(o1.cost, o2.cost);
            }
        });

        q.add(new QEntry(s, 0)); dist[s] = 0;

        while (!q.isEmpty()) {
            QEntry u = q.poll();
            if(u.u == t) return u.cost;
            if(u.cost > dist[u.u]) continue;
            for(int i=0 ; i<graph[u.u].size() ; i++) {
                QEntry v = new QEntry(graph[u.u].get(i).v, u.cost+graph[u.u].get(i).w);
                if(dist[v.u] > v.cost) {
                    dist[v.u] = v.cost;
                    q.add(v);
                }
            }
        }
        return (int)1e9; // inf
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();

        while (tc-->0) {
            int n = sc.nextInt();
            graph = new ArrayList[n]; dist = new int[n];
            for(int i=0 ; i<n ; i++) graph[i] = new ArrayList<>();

            int m = sc.nextInt();
            while (m-->0) {
                int u = sc.nextInt()-1;
                int v = sc.nextInt()-1;
                int w = sc.nextInt();
                graph[u].add(new Link(v,w));
                graph[v].add(new Link(u,w));
            }

            int s = sc.nextInt()-1;
            dijkstra(s, -1);
            for(int i=0 ; i<n ; i++) {
                if(i != s) {
                    if(dist[i] == INF) System.out.print(-1 + " ");
                    if(dist[i] != INF) System.out.print(dist[i] + " ");
                }
            }System.out.println();
        }
    }
}