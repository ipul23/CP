#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,x[20000],hasil;
    long long temp=0;
    scanf("%d",&t);
    for (int i=1; i<=t; i++){
        hasil=0;
        scanf("%d %d",&n,&k);
        for (int j=0; j<k; j++) scanf("%d",&x[j]);
        sort(x,x+k);
        temp=0;
        for (int j=0; j<k; j++){
            if (x[j]>temp+1){
                while (temp<x[j]-1){
                    if (temp>=n) break;
                    temp+=(temp+1);
                    ++hasil;
                }
            }
            if (temp>=n) break;
            temp+=x[j];
        }
            while (temp<n){
                    if (temp>=n) break;
                    temp+=(temp+1);
                    ++hasil;
            }
        printf("Kasus #%d: %d\n",i,hasil);
    }
}
