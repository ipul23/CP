#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,mx=0,start,end;
	string s,s1,s2;
	set<string> st;
	multiset<string> mst;
	map<string,bool> f;
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>s;
		int len=(int)s.length();
		s1.clear();
		for (int j=0; j<(1<<len); j++){
			for (int k=0; k<len; k++) if (j&(1<<k)){
				start=k;
				break;
			}
			for (int k=len-1; k>=0; k--) if (j&(1<<k)){
				end=k;
				break;
			}
			for (int k=start; k<=end; k++){
				if (j&(1<<k)){
					s1+=s[k];
				} else s1+='a';
			}
		if (!f[s1]) mst.insert(s1);
		if (i==0 and !f[s1]) st.insert(s1);
		f[s1]=true;
		s1.clear();
		}
		f.clear();
	}

	for (set<string>::iterator it=st.begin(); it!=st.end(); ++it){
		int temp=0;
		s2=*it;
		for (int j=0; j<s2.length(); j++) if (s2[j]!='a') ++temp;
		if ((int)mst.count(*it)==n){
			mx=max(mx,temp);
		}
	}
	cout<<mx<<endl;
}
