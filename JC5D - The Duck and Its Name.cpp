//The Duck and Its Name
//Tag : Ad-hoc

#include <bits/stdc++.h>
using namespace std;
int t;
string s;

int main(){
	scanf("%d",&t);
	for (int j=1; j<=t; j++){
		cin>>s;
		bool d,u,c,k; 
		d=u=c=k=false;
		for (int i=0; i<s.length(); i++){
			if (s[i]=='d' and !d){
				d=true;
			}
			if (s[i]=='u' and !u and d){
				u=true;
			}
			if (s[i]=='c' and !c and u){
				c=true;
			}
			if (s[i]=='k' and !k and c){
				k=true;
			}
		}
		cout<<"Case #"<<j<<": ";	
		if (d and u and c and k) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
