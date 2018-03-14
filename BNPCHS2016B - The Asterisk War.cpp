#include <bits/stdc++.h>
using namespace std;
int t,n,m,x1,yl,x2,y2,f[305][305];
char data[305][305];

struct tipe{
    int x,y,distance;
};

class CompareDist{
    public:
        bool operator()(tipe& n1, tipe& n2)
        {
           if (n1.distance > n2.distance) 
                return true;
           else
                return false;
        }
};

int dijkstra(int x,int y){
	 priority_queue< tipe, vector< tipe >, CompareDist> q;
	 bool f[305][305]={0};
	 int distance;
	 tipe q1;
	 q1.x=x;q1.y=y;q1.distance=0;
	 q.push(q1);
	 while (!q.empty()){
	 	x=q.top().x; y=q.top().y; distance=q.top().distance;
	 	q.pop();
	 	if (x>=1 and x<=n and y>=1 and y<=m and data[x][y]!='#' and !f[x][y]){
	 		f[x][y]=true;
	 		if (data[x][y]=='T'){
	 			return distance;
	 		}
	 		if (data[x][y]=='*'){
	 			q1.x=x-1; q1.y=y; q1.distance=distance+1;
	 			q.push(q1);
	 			q1.x=x+1; q1.y=y; q1.distance=distance+1;
	 			q.push(q1);
	 			q1.x=x; q1.y=y-1; q1.distance=distance+1;
	 			q.push(q1);
	 			q1.x=x; q1.y=y+1; q1.distance=distance+1;
	 			q.push(q1);
	 		}
	 		else{
	 			q1.x=x-1; q1.y=y; q1.distance=distance;
	 			q.push(q1);
	 			q1.x=x+1; q1.y=y; q1.distance=distance;
	 			q.push(q1);
	 			q1.x=x; q1.y=y-1; q1.distance=distance;
	 			q.push(q1);
	 			q1.x=x; q1.y=y+1; q1.distance=distance;
	 			q.push(q1);
	 		}
	 	}
	 }
	 return -1;
};

int main(){
	scanf("%d",&t);
	for (int i=1; i<=t; i++){
		scanf("%d %d",&n,&m);
		for (int j=1; j<=n; j++){
			getchar();
			for (int k=1; k<=m; k++){
				scanf("%c",&data[j][k]);
				if (data[j][k]=='Y'){
					x1=j; yl=k;
				}
				if (data[j][k]=='T'){
					x2=j; y2=k;
				}
			}
		}
		int hasil=dijkstra(x1,yl);
		printf("Kasus #%d: %d\n",i,hasil);
	}
}