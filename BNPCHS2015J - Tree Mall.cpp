#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,point[20200],x,y;
	bool boo[20200];
	vector<int> f[20200];
	queue<pair<int,int> > q;
	scanf("%d",&t);
	for (int k=0; k<t; k++){
		while (!q.empty()) q.pop();
		scanf("%d",&n);
		memset(boo,0,sizeof(boo));
		for (int j=0; j<n; j++){
			 f[j].clear();
			 point[j]=-1;
		}
		for (int j=0; j<n-1; j++){
			scanf("%d %d",&x,&y);
			f[x-1].push_back(y-1);
			f[y-1].push_back(x-1);
		}
	for (int i=0; i<n; i++){
		if (f[i].size()==1) {
			q.push(make_pair(i,0));
			boo[i]=0;
		}
	}
	
	while (!q.empty()){
		pair<int,int> pr=q.front();
		q.pop();
		if (point[pr.first]==-1){
			point[pr.first]=pr.second;
			for (int i=0; i<f[pr.first].size(); i++){
				if (!boo[f[pr.first][i]]){
					boo[f[pr.first][i]]=true;
					q.push(make_pair(f[pr.first][i],pr.second+1));
				}
			}
		}
	}
	for (int i=0; i<n; i++) if (point[i]==-1) point[i]=0;
	printf("Kasus #%d:\n",k+1);
	for (int i=0; i<n; i++) if (i==0) printf("%d",point[i]);
	else printf(" %d",point[i]);
	printf("\n");
	}
}