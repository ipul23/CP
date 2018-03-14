#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
int dp[21][1111111],hasil;
int n,size[21],data[21][21];

int bitmask(int x,int y){
	if (dp[x][y]!=-1) return dp[x][y]%mod;
	else if (x<n-1) {
		dp[x][y]=0;
		for (int j=0; j<size[x+1]; j++){
			if ((y&(1<<data[x+1][j]))){
				dp[x][y]=(dp[x][y]%mod+bitmask(x+1,y^(1<<data[x+1][j]))%mod)%mod;
			}
		}
	}
	return dp[x][y]%mod;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for (int i=0; i<n; i++){
		scanf("%d",&size[i]);
		for (int j=0; j<size[i]; j++){
			scanf("%d",&data[i][j]);
			--data[i][j];
		}
	}
	for (int i=0; i<=n; i++) dp[i][0]=1;
	for (int i=0; i<size[0]; i++)
		hasil=(hasil%mod+bitmask(0,((1<<n)-1)^(1<<data[0][i]))%mod)%mod;
	cout<<hasil<<endl;
}
