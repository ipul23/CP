//Faris and Graph
//Tag : Graph properties, pattern
#include <bits/stdc++.h>
using namespace std;
int f[11][11]={0},x,y,n,k;

bool cek(int x,int y,int z){
	if (f[x][y] and f[y][z] and f[z][x]) return true;
	if (!f[x][y] and !f[y][z] and !f[z][x]) return true;
	return false;
}
int main(){
	scanf("%d %d",&n,&k);
	if (n>6){
		cout<<"YES"<<endl;
		return 0;
	}
	for (int i=0; i<k; i++){
		scanf("%d %d",&x,&y);
		f[x][y]=1;
		f[y][x]=1;
	}
	for (int i=1; i<=n-2; i++){
		for (int j=i+1; j<=n-1; j++){
			for (int k=j+1; k<=n; k++){
				if (cek(i,j,k)){
					cout<<"YES"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO"<<endl;
}
