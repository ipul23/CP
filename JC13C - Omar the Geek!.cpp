#include <bits/stdc++.h>
#define MX 1000000000000000
using namespace std;
int main(){
    long long n,t,hasil=0,f[5000];
    pair <long long,long long> data[5000];
    scanf("%lld %lld",&n,&t);
    for (int i=0; i<=n-1; i++){
        scanf("%lld %lld" ,&data[i].first,&data[i].second);
    }
    sort(data,data+n);
    for (int i=0; i<=4000; i++) f[i]=MX;
    f[0]=0;
    for (int i=0; i<=n-1; i++){
        for (int j=4000; j>=0; j--){
            if (j-data[i].first>=0 and f[j-data[i].first]<MX){
                f[j]=min(f[j],f[j-data[i].first]+data[i].second);
            }
        }
    }
    for (int i=4000; i>=0; i--){
        if (f[i]<=t){
            hasil=i;
            break;
        }
    }
    printf("%lld\n",hasil);
}
