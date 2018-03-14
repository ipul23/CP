//Going Home
//Indonesia National Contest 2015 - Problem K
//Tag : Shortest Path (Dijkstra)

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> P;
long long t,n,m,q,x,y;
long long jar[30001],jar1[30001],z;

priority_queue< P, vector<P>, greater<P> > pq;
vector <pair<long long,long long> > f[30001],g[30001];

void dijkstra(){
	for (int i=0; i<n; i++) jar[i]=1000000000000000;
	while (!pq.empty()) pq.pop();
	pq.push(make_pair(0,0));
	jar[0]=0;
	while (!pq.empty()){
		pair<long long,long long> temp=pq.top();
		pq.pop();
		if (temp.second>jar[temp.first]) continue;
			if (!f[temp.first].empty())
			for (int i=0; i<(int)f[temp.first].size(); i++){
			long long jarak=jar[temp.first]+f[temp.first][i].second;
				if (jarak<jar[f[temp.first][i].first]){
					jar[f[temp.first][i].first]=jarak;
					pq.push(make_pair(f[temp.first][i].first,jarak));
				}
			}
	}
}

void dijkstra1(){
	for (int i=0; i<n; i++) jar1[i]=1000000000000000;
	while (!pq.empty()) pq.pop();
	pq.push(make_pair(n-1,0));
	jar1[n-1]=0;
	while (!pq.empty()){
		pair<long long,long long> temp=pq.top();
		pq.pop();
		if (temp.second>jar1[temp.first]) continue;
			if (!g[temp.first].empty())
			for (int i=0; i<(int)g[temp.first].size(); i++){
				long long jarak=jar1[temp.first]+g[temp.first][i].second;
				if (jarak<jar1[g[temp.first][i].first]){
					jar1[g[temp.first][i].first]=jarak;
					pq.push(make_pair(g[temp.first][i].first,jarak));
				}
			}
	}
}

int main(){
	scanf("%lld",&t);
	for (int i=1; i<=t; i++){
		scanf("%lld %lld %lld",&n,&m,&q);
		for (int j=0; j<n; j++){
			f[j].clear(); g[j].clear();
		}
		for (int j=1; j<=m; j++){
			scanf("%lld %lld %lld",&x,&y,&z);
			f[x].push_back(make_pair(y,z));
			g[y].push_back(make_pair(x,z));
		}
	dijkstra();
	dijkstra1();
	printf("Case #%d:\n",i);
	for (int j=0; j<q; j++){
		scanf("%lld %lld %lld",&x,&y,&z);
		long long jarak=jar[x]+jar1[y]+z;
		if (n==1){
			printf("NO\n");
			continue;
		}
		if (jar[n-1]>jarak){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	}
	return 0;
}
