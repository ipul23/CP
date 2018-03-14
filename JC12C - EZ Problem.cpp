//EZ Problem
//Tag : Math
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n,m,t;
long long power(long long x,long long y, long long p)
{
    long long res = 1;      // Initialize result

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
    ios::sync_with_stdio(false);
    cin>>t;
    for (int i=0; i<t; i++){
        cin>>n>>m;
        n=n*2+1;
        cout<<(power(2,n-1,mod)%mod*m%mod)%mod<<endl;
    }
}
