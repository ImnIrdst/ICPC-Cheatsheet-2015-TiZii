#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os<<a;return os.str(); }

const int maxn = 1000;

struct st{
	int ants, dpos, dm;
	st( int ants = 0, int dpos = 0, int dm = 0) : ants(ants) , dpos(dpos), dm(dm) {}
	bool operator < ( const st & in ) const {		
		if( ants == in.ants && dpos == in.dpos) return dm < in.dm;
		if( ants == in.ants ) return dpos < in.dpos;
		return ants < in.ants;
	}	
};

char str[10];

map<st,int> dist;

//  4
//2 0 3 5
//  1
int dface[6][4] = {{4,3,1,2},{0,3,2,5},{4,0,1,5},{4,5,1,0},{1,3,2,0},{4,2,1,3}};
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

const int bsize = 4;

int main(){
	
	int T; cin >> T;
	for(int cnt=0 ; cnt<T ; cnt++){
		int ants = 0, dpos = 0, dm = 0, pos =0;
		for(int i=0 ; i<bsize ; i++){
			scanf("%s", str );
			for(int j=0 ; j<bsize ; j++){					
				if( str[j] == 'X' ) {
					ants |= (1<< pos);
				}
				if( str[j] == 'D'){
					dpos = pos;
				}
				pos++;
			}
		}
		st ini(ants, dpos, dm );
		queue<st> q;
		q.push( ini );
		dist.clear();
		dist[ini] = 0;
		int resp = -1;
		while( !q.empty()){
			st cur = q.front(); q.pop();
			if( cur.ants == 0){
				resp = dist[cur]; break;
			}
			int y = cur.dpos / bsize;
			int x = cur.dpos % bsize;			
			REP(i,0,4){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if( ny < 0 || ny >= bsize || nx < 0 || nx >= bsize ) continue;
				int ndpos = (nx + (ny * bsize));				
				int nants = cur.ants;
				int ndm = cur.dm;
				if( cur.dm & (1<<cur.face) ){
					nants |= (1<<cur.dpos); ndm ^= (1<<cur.dpos);
				}
				if( cur.ants & (1<<ndpos) ){
					nants ^= (1<<ndpos ); ndm |= (1<<nface);
				}
				st ncur( nants, ndpos, ndm, nface );
				if( dist.count( ncur ) == 0){
					dist[ncur] = dist[cur] + 1;
					q.push( ncur );
				}
			}
		}
		if( resp == -1) cout << "impossible" << endl;
		else cout << resp << endl;
	}
	
	return 0;
}