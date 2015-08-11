#define MAX (100+10)

int adj[MAX][MAX],path[MAX][MAX]; int n;

void print(int i,int j){
	if(i!=j){
		printf(" %d",i );
		print(path[i][j],j);
	}
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				adj[i][j]=1e9; if(i==j) adj[i][j]=0;
				path[i][j]=j;//initial parent
			}
		}
		
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					if(adj[i][j]>adj[i][k]+adj[k][j]){
						adj[i][j]=adj[i][k]+adj[k][j];
						path[i][j]=path[i][k];//set parent
					}
				}
			}
		}
		int s,d;
		cin >> s >> d;
		printf("%d euros\n",adj[s][d]);

		//this prints the path even if source and distinaion are same
		printf("%d",s); print(path[s][d],d); printf(" %d\n",d);
		
	}
	return 0;
}
