/*INC 2015 - Problem D
Rapid Transit
Tags : BFS*/

#include <bits/stdc++.h>
using namespace std; //titik ,jarak
int t,stasiun,n,a,b,q,data[105];
vector <int> lis[10005];

void bfs(int a,int b){
    pair <int,int > q1; // q1.first , q1.second
    queue <pair <int,int> > q;
    int x,y;
    bool f[10005];
    memset(f,false,sizeof(f));
    q1.first=a; q1.second=0;
    q.push(q1);//q= {a,0}
    int jarak=-1;
    while (!q.empty()){
        x=q.front().first;/*titik*/ y=q.front().second;//jarak
        q.pop();
        if (x==b){
            jarak=y;
            break;
        }
        if (!f[x]){
            f[x]=true;
            for (int i=0; i<lis[x].size(); i++){
                q1.first=lis[x][i];
                q1.second=y+1;
                q.push(q1); //antrian
            }
        }
    }
    printf("%d\n",jarak);
}
int main(){
    scanf("%d",&t);
    for (int i=1; i<=t; i++){
        for (int j=1; j<=10000; j++)
            if (!lis[j].empty()) lis[j].clear();
        printf("Case #%d:\n",i);
        scanf("%d",&stasiun);
        for (int j=1; j<=stasiun; j++){
            scanf("%d",&n);
            for (int k=1; k<=n; k++){
                scanf("%d",&data[k]);
                if (k>1){
                    lis[data[k]].push_back(data[k-1]);
                    lis[data[k-1]].push_back(data[k]);
                }
            }
        }
        scanf("%d",&q);
        for (int j=1; j<=q; j++){
            scanf("%d %d",&a,&b);
            bfs(a,b);
        }
    }
}

