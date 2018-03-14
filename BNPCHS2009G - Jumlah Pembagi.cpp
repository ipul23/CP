//BNPCHS2009G - Jumlah Pembagi
//Tag : Math, Modulo invers, deret

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long hasil,a,b,n;
bool boo=false;
map<long long,long long> f;

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

long long deret(long long a,long long b){
	long long jaw;
	jaw=((power(a,b+1,mod)%mod-1%mod)%mod*power(a-1,mod-2,mod)%mod)%mod;
	return jaw;
}

 
// A function to print all prime factors of a given number n
void faktor(long long n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        ++f[2];
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            ++f[i];
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        ++f[n];
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a>>b;
		if (b==0) {
			cout<<1<<endl;
			continue;
		}
		if (a==0){
			cout<<0<<endl;
			continue;
		}
		f.clear();
		faktor(a);
		hasil=1;
		for (map<long long,long long>::iterator it=f.begin(); it!=f.end(); ++it){
				hasil=(hasil%mod*deret((long long)it->first,(long long)it->second*b)%mod)%mod;
		}
		cout<<hasil<<endl;
	}
}
