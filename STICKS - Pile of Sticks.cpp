#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
int main(){
    long long f[1001][1001]={0},hasil;
    int t,k,n,k1;
    scanf("%d",&t);
    for (int l=1; l<=t; l++){
        hasil=0;
        memset(f,0,sizeof(f));
        scanf("%d %d",&k1,&n);
        if (k1>n) k1=n;
        for (int j=1; j<=n; j++) f[j][j]=1;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=k1; j++){
                if (i-j>0){
                    for (int k=1; k<=k1; k++){
                        f[i][j]=(f[i][j]%mod+f[i-j][k]%mod)%mod;
                    }
                }
            }
        }
        for (int i=1; i<=k1; i++) hasil=(hasil%mod+f[n][i]%mod)%mod;
        printf("Kasus %d: %lld\n",l,hasil);
    }
}
