#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>

using namespace std;

void printpath(int i, map<int,int>& path){
	if(path[i]==-1){ cout << i << endl; return; }
	printpath(path[i], path); cout <<  i << endl;
}

int main(){
	int n; //size of array
	while(cin >> n && n){
		map<int,int> path; int tmp;
		multiset<int> st ; multiset<int>::iterator it, it2;
		for(int i=0 ; i<n ; i++){
			cin >> tmp; // element of array

			st.insert(tmp); it = st.find(tmp); cout << *it << " * " ; 
			//while(it!=st.end() && *it==tmp) it++; if(it==st.end() || *it!=tmp) it--; // with repetitive, but for print path must use a pair(tmp, idx)
			if(it==st.begin()) path[tmp]=-1;      else it--, path[tmp]=*it, it++;// for printing 

			cout << *it << " * " << st.size() << endl;
			it++; if(it!=st.end()) st.erase(it);
			for(it2 = st.begin() ; it2!=st.end() ; it2++) 
				cout << *it2 << " ,"; cout << endl; //for Debug
		}
		cout << "LIS: " << st.size() << endl;
		it = st.end(); it--; printpath(*it, path);
	}
}