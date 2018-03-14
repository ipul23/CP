//INC2016I - Irpin's Walk
//Tag : Shortest Path, Dijkstra, two dimension
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,u,v,w,t;
int hasil,ran[65];

vector <int> walk[11100],dist[11100];

struct tipe{
    int point,compare,distance,path;
};

class CompareDist{
    public:
        bool operator()(tipe& n1, tipe& n2)
        {
           if (n1.compare >= n2.compare)
                return true;
           else
                return false;
        }
};

int dijkstra(int a,int b){

	int point,compare,distance,path;
	int f[11100][65],hasil;
	tipe q1;
	priority_queue <tipe ,vector<tipe> ,CompareDist> q;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=31; j++) f[i][j]=1073741824;
	hasil=1073741824;
	q1.point=a;
	q1.distance=0;
	q1.compare=0;
	q1.path=0;
	q.push(q1);
	while (!q.empty()){
		path=q.top().path; point=q.top().point; distance=q.top().distance; compare=q.top().compare;
		q.pop();
		if ((f[point][path]>compare and path<=30) or (path>30 and f[point][31]>compare)){
		if (path<=30) f[point][path]=compare;
		else f[point][31]=compare;
			if (point!=b){
				if (walk[point].size()>0)
				for (int i=0; i<walk[point].size(); i++){
						if (path+1>30 or ran[path+1]>distance+dist[point][i]){
							q1.distance=distance+dist[point][i];
							q1.compare=distance+dist[point][i];
							q1.point=walk[point][i];
							q1.path=path+1;
							q.push(q1);
						}
						else{
							q1.distance=distance+dist[point][i];
							q1.compare=2*(distance+dist[point][i]);
							q1.point=walk[point][i];
							q1.path=path+1;
							q.push(q1);
						}
				}
			}
		}
	}
	for (int i=0; i<=31; i++)
		hasil=min(hasil,f[b][i]);
	if (hasil<1073741824) return hasil;
	else
	return -1;
}

int main(){
	ran[0]=1;
	for (int i=1; i<=31; i++){
		ran[i]=ran[i-1]*2;
	}
	scanf("%d",&t);
	for (int i=1; i<=t; i++){
		scanf("%d %d %d %d",&n,&m,&a,&b);
		for (int j=0; j<=n; j++){
			walk[j].clear();
			dist[j].clear();
		}
		for (int j=1; j<=m; j++){
			scanf("%d %d %d",&u,&v,&w);
			walk[u].push_back(v);
			walk[v].push_back(u);
			dist[u].push_back(w);
			dist[v].push_back(w);
		}
		hasil=dijkstra(a,b);
		printf("Case #%d: %d\n",i,hasil);
	}
}
