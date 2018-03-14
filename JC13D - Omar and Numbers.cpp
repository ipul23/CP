/*
Omar and Numbers
Tags : Math, Phi-Value*/
#include <bits/stdc++.h>
using namespace std;
long long n,v,ans;

long long phi(long long n)
{
    long long result = n;   // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p=2; p*p<=n; ++p)
    {
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}
long long fpb(long long x,long long y){
    if (y==0) return x;
    return fpb(y,x%y);
}
int main(){
    scanf("%lld",&n);
    v=1;
    while (v*v<n){
        ++v;
    }
    long long v1=1;
    while (v1<=sqrt(n)){
        if (fpb(n,v1)==1) --ans;
        ++v1;
    }
    ans=ans+phi(n);
    printf("%lld\n",ans);
}
