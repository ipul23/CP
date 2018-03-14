//Rank Query
//Indonesia National Contest 2015 - Problem H
//Tag : Merge Sort Tree / Persistent Segment Tree

#include <bits/stdc++.h>
using namespace std;
int x,y,z,n,q,t,ans = 0,a[10006]={0};
pair<int,int> A[10006];
vector<int> tree[5*10006];

void build(int node,int start,int end){
	if (start == end){
		tree[node].push_back(a[start]);
	} else{
		int mid = (start + end) / 2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(),back_inserter(tree[node]));
	}
}

int query(int node,int start,int end,int l,int r,int val){
	if (start > r or end < l or start > end)
		return 0;
	if (start>=l and end<=r){
		return upper_bound(tree[node].begin(),tree[node].end(),val) - tree[node].begin();
	}
	int mid = (start + end)/2;
	int p1 = query(node*2,start,mid,l,r,val);
	int p2 = query(node*2+1,mid+1,end,l,r,val);
	return (p1+p2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int i = 0; i<t; i++){
		cin>>n>>q;
		for (int j=0; j<n; j++){
			cin>>A[j].first;
			A[j].second = j;	
		} 
		sort(A,A+n);
		for (int j=0; j<n; j++){
			a[A[j].second] = j;
		}
		for (int j=0; j<=4*n; j++) tree[j].clear();
		build(1,0,n-1);
		cout<<"Case #"<<i+1<<":\n";
		for (int j=0; j<q; j++){
			cin>>x>>y>>z;
			int l = 0,r = n-1,mid;
			while (l <= r){
				mid = (l+r)/2;
				int temp  = query(1,0,n-1,x-1,y-1,mid);
				if (temp >= z){
					ans = mid;
					r = mid - 1;
				} else
					l = mid + 1;
			}
			cout<<A[ans].first<<"\n";
		}
	}
}
