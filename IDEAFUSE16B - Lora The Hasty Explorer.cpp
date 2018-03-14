/*Ideafuse 2016 - Problem B
Lora The Hasty Explorer
Tags : BFS*/
#include <bits/stdc++.h>
using namespace std;

// Bismillahirrahmaanirrahiim;

typedef long long ll;
typedef double db;

// READ WRITE PART
inline void in(int &a) {scanf("%d",&a);}
inline void out(int a) {printf("%d\n",a);}
inline void in(int &a,int &b) {scanf("%d%d",&a,&b);}
inline void out(int a,int b) {printf("%d %d\n",a,b);}

inline void inl(ll &a) {scanf("%lld",&a);}
inline void inl(ll &a,ll &b) {scanf("%lld%lld",&a,&b);}
inline void outl(ll a) {printf("%lld\n",a);}
inline void outl(ll a, ll b) {printf("%lld %lld\n",a,b);}
// ENDOF READ WRITE PART

#define reset(i, n) memset(i, n, sizeof(i))

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,n,a) for(int i=n;i>=a;i--)
#define FORZ(i,b) for(int i=0;i<b;i++)
#define loop(n) while(n--)

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back

#define debug puts("this-part-has-been-reached")

int gcd(int a, int b) {return b ? gcd(b, a%b): a;}
int lcm(int a, int b) {return a/gcd(a, b)*b;}

// ======================================================== //

int n, m, svi, svj;
char petah[65][65];
int x, y, jarak, a1, a2, a3, a4;

bool f[65][65][2][2][2][2];

struct mystruct{
    int x, y, jarak, a1, a2, a3, a4;
};

mystruct s;
queue<mystruct> q;

void bfs(int i, int j)
{
    memset(f, false, sizeof(f));
    s.x = i; s.y = j; s.a1 = 0; s.a2 = 0; s.a3 = 0; s.a4 = 0; s.jarak =0;
    while(q.size()) q.pop(); q.push(s);
    while(q.size())
    {
        x = q.front().x; y = q.front().y; jarak = q.front().jarak;
        a1 = q.front().a1; a2 = q.front().a2; a3 = q.front().a3; a4 = q.front().a4;
        q.pop();

        if (a1==1 && a2==1 && a3==1 && a4==1 && petah[x][y]=='E')
        {
            cout << jarak << endl;
            return;
        }

        int ta1 = a1, ta2 = a2, ta3 = a3, ta4 = a4;
        if (x>=1 && x<=n && y>=1 && y<=m && !f[x][y][a1][a2][a3][a4])
        {
            f[x][y][a1][a2][a3][a4] = true;
            if (petah[x+1][y]!='#')
            {
                if (petah[x+1][y]=='1') a1=1;
                if (petah[x+1][y]=='2') a2=1;
                if (petah[x+1][y]=='3') a3=1;
                if (petah[x+1][y]=='4') a4=1;
                s.x = x+1; s.y = y; s.jarak = jarak+1;
                s.a1 = a1; s.a2 = a2; s.a3 = a3; s.a4 = a4;
                q.push(s);
            }
            a1 = ta1; a2 = ta2; a3 = ta3; a4 = ta4;
            if (petah[x-1][y]!='#')
            {
                if (petah[x-1][y]=='1') a1=1;
                if (petah[x-1][y]=='2') a2=1;
                if (petah[x-1][y]=='3') a3=1;
                if (petah[x-1][y]=='4') a4=1;
                s.x = x-1; s.y = y; s.jarak = jarak+1;
                s.a1 = a1; s.a2 = a2; s.a3 = a3; s.a4 = a4;
                q.push(s);
            }
            a1 = ta1; a2 = ta2; a3 = ta3; a4 = ta4;
            if (petah[x][y+1]!='#')
            {
                if (petah[x][y+1]=='1') a1=1;
                if (petah[x][y+1]=='2') a2=1;
                if (petah[x][y+1]=='3') a3=1;
                if (petah[x][y+1]=='4') a4=1;
                s.x = x; s.y = y+1; s.jarak = jarak+1;
                s.a1 = a1; s.a2 = a2; s.a3 = a3; s.a4 = a4;
                q.push(s);
            }
            a1 = ta1; a2 = ta2; a3 = ta3; a4 = ta4;
            if (petah[x][y-1]!='#')
            {
                if (petah[x][y-1]=='1') a1=1;
                if (petah[x][y-1]=='2') a2=1;
                if (petah[x][y-1]=='3') a3=1;
                if (petah[x][y-1]=='4') a4=1;
                s.x = x; s.y = y-1; s.jarak = jarak+1;
                s.a1 = a1; s.a2 = a2; s.a3 = a3; s.a4 = a4;
                q.push(s);
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    in(n, m);
    for (int i=1; i<=n; i++)
    {
    	getchar();
        for (int j=1; j<=m; j++)
        {
            sf("%c", &petah[i][j]);
            if (petah[i][j]=='E') {svi = i; svj = j;}
        }
    }
    bfs(svi, svj);
}
