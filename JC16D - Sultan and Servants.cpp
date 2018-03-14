//Sultan and Servants
//Tag : Data Structure, Set, Pointer

#include <bits/stdc++.h>
using namespace std;	
multiset<int>::iterator it;
multiset<int> myset;
int n,q,data[2000],cnt=0,f[100500],lef,righ,idx;
pair<int, pair<int,int> > range[100500];
int main(){
	scanf("%d %d",&n,&q);
	for (int i=1; i<=n; i++) scanf("%d",&data[i]);
	for (int j=0; j<q; j++){
		scanf("%d %d",&range[j].first,&range[j].second.first);
		range[j].second.second=j;
	}
	sort(range,range+q);
	for (int i=0; i<q; i++){
		lef=range[i].first; righ=range[i].second.first; idx=range[i].second.second;
		if (i==0 or range[i].first!=range[i-1].first){
			myset.clear(); cnt=0;
			for (int j=range[i].first; j<=range[i].second.first; j++) myset.insert(data[j]);
			for (it=myset.begin(); it!=myset.end(); it++){
				++cnt;
				if ((righ-lef+2)/2==cnt){
					f[idx]=*it;
					break;
				}
			}
		}
		else{
			for (int j=range[i-1].second.first+1; j<=range[i].second.first; j++){
				if (data[j]>=*it) myset.insert(data[j]);
				else{
					myset.insert(data[j]);
					--it;
				}
			}
			while (cnt<(righ-lef+2)/2){
				++it;
				++cnt;
			}
			f[idx]=*it;
		}
	}
	for (int i=0; i<q; i++) printf("%d\n",f[i]);
} 
