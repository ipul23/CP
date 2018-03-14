#include <bits/stdc++.h>
using namespace std;
struct tipe{
    int x,y,distance;
    char str;
};

class CompareDist{
    public:
        bool operator()(tipe& n1, tipe& n2)
        {
           if (n1.distance >= n2.distance)
                return true;
           else
                return false;
        }
};
int n,m,t,hasil;
char ch[2000][2000];
tipe a,b;

int dijkstra(int x,int y){
    priority_queue <tipe ,vector<tipe> ,CompareDist> q;
    while (!q.empty()) q.pop();
    int f[1010][1010][4];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
                f[i][j][0]=2000000000;
                f[i][j][1]=2000000000;
                f[i][j][2]=2000000000;
                f[i][j][3]=2000000000;
        }
    char str='O';
    int distance=0,z=0;
    tipe q1;
    q1.x=x; q1.y=y; q1.distance=0; q1.str='O';
    q.push(q1);
    while (!q.empty()){
        x=q.top().x; y=q.top().y; distance=q.top().distance; str=q.top().str;
        if (str=='L') z=0;
        else
        if (str=='R') z=1;
        else
        if (str=='D') z=2;
        else
            z=3;
        q.pop();
        if (x>=1 and x<=n and y>=1 and y<=m and distance<f[x][y][z]){
            f[x][y][z]=distance;
            if (x==b.x and y==b.y) return distance;
            if (str=='O'){
                if (ch[x-1][y]=='#'){
                    q1.x=x-1; q1.y=y; q1.distance=distance+1; q1.str='U';
                    q.push(q1);
                }
                else{
                    q1.x=x-1; q1.y=y; q1.distance=distance; q1.str='O';
                    q.push(q1);
                }
                if (ch[x+1][y]=='#'){
                    q1.x=x+1; q1.y=y; q1.distance=distance+1; q1.str='D';
                    q.push(q1);
                }
                else{
                    q1.x=x+1; q1.y=y; q1.distance=distance; q1.str='O';
                    q.push(q1);
                }
                if (ch[x][y-1]=='#'){
                    q1.x=x; q1.y=y-1; q1.distance=distance+1; q1.str='L';
                    q.push(q1);
                }
                else{
                    q1.x=x; q1.y=y-1; q1.distance=distance; q1.str='O';
                    q.push(q1);
                }
                if (ch[x][y+1]=='#'){
                    q1.x=x; q1.y=y+1; q1.distance=distance+1; q1.str='R';
                    q.push(q1);
                }
                else{
                    q1.x=x; q1.y=y+1; q1.distance=distance; q1.str='O';
                    q.push(q1);
                }
            }
            else{
                if (str=='U'){
                 if (ch[x-1][y]=='#'){
                    q1.x=x-1; q1.y=y; q1.distance=distance; q1.str='U';
                    q.push(q1);
                }
                else{
                    q1.x=x-1; q1.y=y; q1.distance=distance; q1.str='O';
                    q.push(q1);
                }
                }
                if (str=='D'){
                if (ch[x+1][y]=='#'){
                    q1.x=x+1; q1.y=y; q1.distance=distance; q1.str='D';
                    q.push(q1);
                }
                else{
                    q1.x=x+1; q1.y=y; q1.distance=distance; q1.str='O';
                    q.push(q1);
                }
                }
                if (str=='L'){
                if (ch[x][y-1]=='#'){
                    q1.x=x; q1.y=y-1; q1.distance=distance; q1.str='L';
                    q.push(q1);
                }
                else{
                    q1.x=x; q1.y=y-1; q1.distance=distance; q1.str='O';
                    q.push(q1);
                }
                }
                if (str=='R'){
                if (ch[x][y+1]=='#'){
                    q1.x=x; q1.y=y+1; q1.distance=distance; q1.str='R';
                    q.push(q1);
                }
                else{
                    q1.x=x; q1.y=y+1; q1.distance=distance; q1.str='O';
                    q.push(q1);
                }
                }
            }
        }
    }
}
int  main(){
    scanf("%d",&t);
    for (int i=1; i<=t; i++){
        hasil=0;
        scanf("%d %d",&n,&m);
        for (int j=1; j<=n; j++){
            getchar();
            for (int k=1; k<=m; k++){
                scanf("%c",&ch[j][k]);
                if (ch[j][k]=='A') {
                    a.x=j;
                    a.y=k;
                }
                if (ch[j][k]=='X'){
                    b.x=j;
                    b.y=k;
                }
            }
        }
        hasil=dijkstra(a.x,a.y);
        printf("%d\n",hasil);
    }
    return 0;
}
