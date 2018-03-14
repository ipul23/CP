//Wakka dan Perpustakaan Raksasa
//BNPCHS 2014 - Problem J
//Tag : Prefix-Sum

#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t,mx,n,hasil,lef[20005]={0},righ[20005]={0};
	pair<int,int> data[20005];
	cin>>t;
	for (int i=1; i<=t; i++){
		cin>>n;
		mx=0;
		hasil=2000000000;
		memset(lef,0,sizeof(0));
		memset(righ,0,sizeof(0));
		for (int j=0; j<n; j++) {
			cin>>data[j].first>>data[j].second;
			mx=max(mx,data[j].second);
		}
		sort(data,data+n);
		lef[0]=0;
		righ[n-1]=0;
		for (int j=1; j<n; j++){
			lef[j]=lef[j-1]+(data[j].first-data[j-1].first)*j;
		}
		for (int j=n-2; j>=0; j--){
			righ[j]=righ[j+1]+(data[j+1].first-data[j].first)*(n-j-1);
		}
		for (int j=0; j<n; j++){
			hasil=min(hasil,lef[j]+righ[j]+mx);
		}
		cout<<"Kasus #"<<i<<": "<<hasil<<endl;
	}
}
