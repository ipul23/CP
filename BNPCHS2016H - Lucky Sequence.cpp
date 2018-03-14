#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,cnt1,cnt;
    double hasil,bagi;
    scanf("%d",&t);
    for (int i=1; i<=t; i++){
        long long ar[100000]={0},sel[100000]={0},beda1[100000]={0},beda2[100000]={0},up,x;
        scanf("%d",&n);
        hasil=0; bagi=0;
        cnt1=cnt=0;
        cnt=1;
        ar[cnt]=0;
        for (int j=1; j<=n; j++){
            scanf("%d",&x);
            if (x==1){
                ++cnt;
                ar[cnt]=j;
            }
        }
        ++cnt;
        cnt1=0;
        ar[cnt]=n+1;
        for (int j=2; j<=cnt; j++){
            ++cnt1;
            sel[cnt1]=ar[j]-ar[j-1];
        }
        beda1[1]=0;
        beda2[1]=0;
        up=0;
        for (int j=2; j<=cnt1; j++){
            ++up;
            beda1[j]=beda1[j-1]+sel[j];
            beda2[j]=beda2[j-1]+sel[j]*up;
        }
        up=0;
        for (int j=1; j<=cnt1; j++){
            hasil=hasil+sel[j]*(beda2[cnt1]-beda2[j])-up*sel[j]*(beda1[cnt1]-beda1[j]);
            ++up;
        }
        bagi=(n*(n+1)/2);
        hasil=hasil/bagi;
        printf("Kasus #%d: %.3lf\n",i,hasil);
    }
}
