#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,hasil,data[3000];
	scanf("%d",&t);
	for (int i=1; i<=t; i++){
		scanf("%d",&n);
		for (int j=1; j<=n; j++) scanf("%d",&data[j]);
		hasil=min(data[1],data[n]);
		printf("Case #%d: %d\n",i,hasil);
	}
}