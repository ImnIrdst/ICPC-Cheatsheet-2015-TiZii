#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define MAX (100+10)

using namespace std;

string str1,str2; int d[MAX][MAX]; char path[MAX][MAX];

int Step,DelCnt,InsCnt;
void PrintPath(int i, int j){
	//cout << path[i][j] << endl;
	if(path[i][j]==0) PrintPath(i-1,j-1);
	else if(path[i][j]=='d'){
		PrintPath(i-1,j);
		printf("%d Delete %d\n", Step++, i + InsCnt - DelCnt);
		DelCnt++;
	}
	else if(path[i][j]=='i'){
		PrintPath(i,j-1);
		printf("%d Insert %d,%c\n", Step++, j, str2[j]);
		InsCnt++;
	}
	else if(path[i][j]=='r'){
		PrintPath(i-1,j-1);
		printf("%d Replace %d,%c\n", Step++, i + InsCnt - DelCnt, str2[j]);
	}
}

int solve(){
	memset(d,0,sizeof d); memset(path,0,sizeof path);
	for(int i=1 ; i<=str1.length() ; i++){
		d[i][0]=i; path[i][0]='d';
	}
	for(int j=1 ; j<=str2.length() ; j++){
		d[0][j]=j; path[0][j]='i';
	}
	int del,ins,Rplc;
	for(int i=1 ; i<=str1.length() ; i++){
		for(int j=1 ; j<=str2.length() ; j++){
			del=d[i-1][j]+1;
			ins=d[i][j-1]+1;
			Rplc=d[i-1][j-1]+(str1[i]!=str2[j]);
			d[i][j]=min(min(del,ins),Rplc);

			if(d[i][j]==del) path[i][j]='d';
			else if(d[i][j]==ins) path[i][j]='i';
			else if(str1[i]!=str2[j]) path[i][j]='r';

		}
	}
	return d[str1.length()][str2.length()];
}

int main(){
	int t=1;
	while(getline(cin,str1) && getline(cin,str2)){	
		if(t++!=1) cout << endl; str1=' '+str1; str2=' '+str2;
		cout << solve() << endl; Step=1; InsCnt=DelCnt=0;
		PrintPath(str1.length(), str2.length());
	}
}