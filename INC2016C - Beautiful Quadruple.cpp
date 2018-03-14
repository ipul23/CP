#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n,m1,data[200][200],hasil;
	vector <int> v;
	unordered_map <int,int> m;
	scanf("%d",&t);
	for (int i=1; i<=t; i++){
		hasil=0;
		scanf("%d %d",&n,&m1);
		for (int j=1; j<=n; j++)
			for (int k=1; k<=m1; k++) scanf("%d",&data[j][k]);
		for (int j=1; j<=m1-1; j++){
			for (int k=j+1; k<=m1; k++){
				m.clear();
				v.clear();
				for (int l=1; l<=n; l++){
					if (data[l][j]==data[l][k]){
						if (m[data[l][j]]==0){
							v.push_back(data[l][j]);
						}
						++m[data[l][j]];
					}	
				}
				for (int l=0; l<v.size(); l++){
					hasil+=(m[v[l]]*(m[v[l]]-1)/2);
				}
			}
		}
		printf("Case #%d: %d\n",i,hasil);
	}
	return 0;
}