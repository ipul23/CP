//The Duck and Social Media
//Tag : Ad-hoc
#include <bits/stdc++.h>
using namespace std;
int t,ans,n,x;
map<long long,bool> f;
int main(){
	scanf("%d",&t);
	for (int i=1; i<=t; i++){
		scanf("%d",&n);
		f.clear(); ans=0;
		for (int j=1; j<=n; j++){
			scanf("%d",&x);
			if (!f[x]){
				f[x]=true;
				++ans;
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
}
