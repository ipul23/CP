//The Duck and The Man's Keyboard
//Tag : Ad-hoc
#include <bits/stdc++.h>
using namespace std;
int t;
string s;

int fung(char x,char y,int z){
	int temp=z;
	for (int j=0; j<x-y; j++)
		temp=temp*10+z;
	return temp;
}

int main(){
	cin>>t;
	for (int i=0; i<t; i++){
		cin>>s;
		cout<<"Case #"<<i+1<<": ";
		for (int j=0; j<s.length(); j++){
			if (j>0) cout<<' ';
			if (s[j]>='A' and s[j]<='C'){
				cout<<fung(s[j],'A',2);
			}
			else
			if (s[j]>='D' and s[j]<='F'){
				cout<<fung(s[j],'D',3);
			}
			else
			if (s[j]>='G' and s[j]<='I'){
				cout<<fung(s[j],'G',4);
			}
			else
			if (s[j]>='J' and s[j]<='L'){
				cout<<fung(s[j],'J',5);
			}
			else
			if (s[j]>='M' and s[j]<='O'){
				cout<<fung(s[j],'M',6);
			}
			else
			if (s[j]>='P' and s[j]<='S'){
				cout<<fung(s[j],'P',7);
			}
			else
			if (s[j]>='T' and s[j]<='V'){
				cout<<fung(s[j],'T',8);
			}
			else
			if (s[j]>='W' and s[j]<='Z'){
				cout<<fung(s[j],'W',9);
			}
		}
		cout<<endl;
	}
}
