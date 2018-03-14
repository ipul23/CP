//Domino
//ACM-ICPC MultiProvincial Ideafuse 2016 - Problem H
//Tag : Eulerian path

#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,odd,con,res;
bool f[10]={0};
vector<int> v[10];

void dfs(int x){
	for (int i=0; i<v[x].size(); i++){
		if (!f[v[x][i]]){
			if ((int)v[v[x][i]].size()%2==1) ++odd;
			f[v[x][i]] = true;
			dfs(v[x][i]);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	for (int i=1; i<=t; i++){
		cin>>n;
		for (int j=0; j<=6; j++) v[j].clear();
		memset(f,0,sizeof(f));
		res=0;
		con=0;
		for (int j=1; j<=n; j++){
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int j=0; j<=6; j++){
			if (!f[j] and !v[j].empty()) {
				odd=0;
				f[j]=true;
				if ((int)v[j].size()%2==1) ++odd;
				dfs(j);
				if (odd>=2) res+=(odd/2-1);
				++con;
			}
		}
		if (con>0) res+=(con-1);
		cout<<"Case #"<<i<<": "<<res<<"\n";
	}
}
