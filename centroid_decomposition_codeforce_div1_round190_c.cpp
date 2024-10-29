#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int sz[N],c[N];
bool rem[N];
vector<int> adj[N];
void dfs(int u,int p){
    sz[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p || rem[v]) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int getcentroid(int u,int p,int treesz){
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p || rem[v]) continue;
        if(sz[v]*2>treesz) return getcentroid(v,u,treesz);
    }
    return u;
}
void builddec(int u,int lvl){
    dfs(u,-1);
    int cen=getcentroid(u,-1,sz[u]);
    //cout<<u <<" " <<cen <<" " <<sz[u]<<"\n";
    rem[cen]=true;
    c[cen]=lvl;
    for(int i=0;i<adj[cen].size();i++){
        int v=adj[cen][i];
        if(rem[v]) continue;
        builddec(v,lvl+1);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    builddec(1,0);
    for(int i=1;i<=n;i++) cout<<(char)('A'+c[i]) <<" ";
}
