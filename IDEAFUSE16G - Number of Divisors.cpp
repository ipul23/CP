#include<bits/stdc++.h>
using namespace std;
int k[1000002]={0};
vector <int> data[1000005];

void sieve (int n)
{
	for (int p=2; p<=n; p++)
    {
        for (int i=2; i*p<=n; i++)
        {
        	++k[i*p];
        }
    }
    k[1]=-1;
}

void olah (int n)
{
	for(int i=1;i<=n;i++)
	{
		data[k[i]+2].push_back(i);
	}
}

int main ()
{
    int n, jumlah,a,b,c,h=1;
    int l,r,mid,idxa,idxb;
    scanf("%d", &n);
    sieve(1000000);
    olah(1000000);
    while(n--)
    {
    	jumlah=0;
        scanf("%d %d %d", &a, &b ,&c);
        idxa=-1;idxb=-1;
        l=0 ; r=data[c].size()-1;
        if (!data[c].empty())
        while(l<=r)
        {
        	mid=(l+r)/2;
        	if(data[c][mid]>=a)
        	{
        		r=mid-1;
        		idxa=mid;
        	}
        	else
        	{
        		l=mid+1;
        	}
        }
        l=0 ; r=data[c].size()-1;
        if (!data[c].empty())
        while(l<=r)
        {
        	mid=(l+r)/2;
        	if(data[c][mid]<=b)
        	{
        		l=mid+1;
        		idxb=mid;
        	}
        	else
        	{
        		r=mid-1;
        	}
        }
   		printf("Case #%d: ", h);
   		if (idxb!=-1 and idxa!=-1)
        printf("%d\n", idxb-idxa+1);
        else printf("0\n");
        h++;
    }
    return 0;
}
