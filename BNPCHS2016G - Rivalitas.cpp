#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;
long long power(long long x,long long y, long long p)
{
    int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main(){
    int x,n;
    long long f[1000005],finvrs[1000005];
    f[0]=1;
    finvrs[0]=1;
    for (int i=1; i<=1000000; i++){
        f[i]=(f[i-1]%mod*i%mod)%mod;
        finvrs[i]=(finvrs[i-1]%mod*power(i,mod-2,mod)%mod)%mod;
    }
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%d",&x);
        int hasil=0;
        if (x%2==0){
            for (int j=0; j<=x/2-1; j++){
                hasil=(hasil+(((finvrs[x-j]*finvrs[j])%mod*finvrs[x-(j+1)])%mod*finvrs[j+1])%mod)%mod;
            }
            hasil=(((2*f[x])%mod*f[x])%mod*hasil)%mod;
        }
        else{
            for (int j=0; j<=x/2-1; j++){
                hasil=(hasil+(((finvrs[x-j]*finvrs[j])%mod*finvrs[x-(j+1)])%mod*finvrs[j+1])%mod)%mod;
            }
            hasil=((((2*f[x])%mod*f[x])%mod*hasil)%mod+(((((f[x]*f[x])%mod*finvrs[x/2])%mod*finvrs[x-x/2])%mod*finvrs[x/2+1])%mod*finvrs[x-(x/2+1)])%mod)%mod;
        }
        printf("Kasus #%d: %d\n",i,hasil);
    }
}
