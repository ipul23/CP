#include <bits/stdc++.h>
using namespace std;
int t,n,m,r,a,selec[30000],parent[30000],x,cnt,hasil,b;
vector <int> lst[30000],ans,v;
queue <int> q;
// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }

    return r;
}

int LongestIncreasingSubsequenceLength() {
    if (v.size() == 0)
        return 0;

    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            // new smallest value
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            // v[i] extends largest subsequence
            tail[length++] = v[i];
        else
            // v[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
            // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }

    return length;
}

int main(){
    scanf("%d",&t);
    for (int i=1; i<=t; i++){
        memset(parent,0,sizeof(parent));
        memset(selec,0,sizeof(selec));
        ans.clear();
        scanf("%d %d %d",&n,&m,&r);
        for (int j=0; j<=n; j++) lst[j].clear();
        for (int j=0; j<m; j++) {
            scanf("%d",&selec[j]);
        }
        sort(selec,selec+m);
        selec[m]=999999;
        for (int j=1; j<=r; j++){
            scanf("%d %d",&a,&b);
            lst[a].push_back(b);
            ++parent[b];
        }
        for(int j=1; j<=n; j++){
            sort(lst[j].begin(),lst[j].end());
            if (parent[j]==0){
                q.push(j);
            }
        }
        while (!q.empty()){
            x=q.front();
            ans.push_back(x);
            q.pop();
            for (int j=0; j<lst[x].size(); j++){
                --parent[lst[x][j]];
                if (parent[lst[x][j]]==0){
                    q.push(lst[x][j]);
                }
            }
        }
        cnt=0;
        hasil=0;
        int prev=0;
        for (int j=0; j<ans.size(); j++){
            if (ans[j]==selec[cnt]){
                ++hasil;
                for (int k=prev; k<=j-1; k++){
                    if (ans[k]<selec[cnt] and ans[k]>selec[cnt-1]) v.push_back(ans[k]);
                }
                hasil+=LongestIncreasingSubsequenceLength();
                v.clear();
                ++cnt;
                prev=j+1;
            }
        }
        for (int k=prev; k<ans.size(); k++){
            if (ans[k]<selec[cnt] and ans[k]>selec[cnt-1]) v.push_back(ans[k]);
        }
        hasil+=LongestIncreasingSubsequenceLength();
        v.clear();
        printf("Case #%d: %d\n",i,hasil);
    }
}
