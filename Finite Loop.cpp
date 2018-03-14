//Finite Loop
//Tag : Bruteforce (optimize)

#include <bits/stdc++.h>
using namespace std;
long long a,c,p,x,y,t;
bool boo;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	for (int i=1; i<=t; i++){
		cin>>a>>c>>p;
		boo = false;
		x = 1;
		y = c+1;
		for (int j=1; j<=p-1; j++){
			x = x*a;
			x = x - (x/p)*p;
			if (x == y){
				cout<<"Case #"<<i<<": "<<j<<"\n";
				boo=true;
				break;
			}
		}
		if (!boo) cout<<"Case #"<<i<<": "<<-1<<"\n";
	}
}
