//IDEAFUSE16J - Maximum Matrix Cover
//Tag : Dynamic-Programming

#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int t,a,b,data[55][55]={0},sum[55][55]={0},f[55][55]={0},hasil=0;
	cin>>t;
	for (int i=1; i<=t; i++){
		hasil=-2000000000;
		memset(sum,0,sizeof(sum));
		cin>>a>>b;
		for (int j=0; j<=a; j++)
			for (int k=1; k<=b; k++) f[j][k]=-1000000000;
		for (int j=1; j<=a; j++)
			for (int k=1; k<=a; k++){
				cin>>data[j][k];
				sum[j][k]=data[j][k]+sum[j-1][k]+sum[j][k-1]-sum[j-1][k-1];
			}
		for (int j=1; j<=b; j++){
			for (int k=1; k<=a; k++){
				for (int l=k-1; l>=0; l--){
					for (int m=l; m>=0; m--){
						f[k][j]=max(f[k][j],f[m][j-1]+sum[k][k]-sum[l][k]-sum[k][l]+sum[l][l]);
					}
				}
			}
		}
		for (int j=1; j<=a; j++){ 
			//cout<<f[j][b]<<endl;
			hasil=max(hasil,f[j][b]);
		}
		cout<<"Case #"<<i<<": "<<hasil<<endl;
	}
}
