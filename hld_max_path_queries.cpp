#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1<<19;
long long val[N],s[M];
int lvl[N],pa[N],sz[N],t[N],now=1,top[N],con[N];
int n,ret;
vector<int> adj[N];
void build(int l,int r,int idx){
    if(l==r){
        s[idx]=con[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    s[idx]=max(s[idx*2],s[idx*2+1]);
}
void update(int l,int r,int idx,int a,long long b){
    if(a>r || a<l) return;
    if(l==r){
        s[idx]=b;
        return;
    }
    int m=(l+r)/2;
    update(l,m,idx*2,a,b);
    update(m+1,r,idx*2+1,a,b);
    s[idx]=max(s[idx*2],s[idx*2+1]);
}
int query(int l,int r,int idx,int a,int b){
    if(a>r || b<l) return 0;
    if(a<=l && b>=r) return s[idx];
    int m=(l+r)/2;
    return max(query(l,m,idx*2,a,b),query(m+1,r,idx*2+1,a,b));
}
void dfs(int u,int p,int l){
    lvl[u]=l,pa[u]=p,sz[u]=1;
    int tmp=sz[p];
    sz[p]=0;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p) continue;
        dfs(v,u,l+1);
        sz[u]+=sz[v];
        if(sz[v]>sz[adj[u][0]]) swap(adj[u][i],adj[u][0]);
    }
    sz[p]=tmp;
}
void hld(int u,int p){
    t[u]=now++;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p) continue;
        if(v==adj[u][0]) top[v]=top[u];
        else top[v]=v;
        hld(v,u);
    }
}
int path(int u,int v){
    while(top[u]!=top[v]){
        if(lvl[top[u]]<lvl[top[v]]) swap(u,v);
        ret=max(ret,query(1,n,1,t[top[u]],t[u]));
        u=pa[top[u]];
    }
    if(lvl[u]>lvl[v]) swap(u,v);
    ret=max(ret,query(1,n,1,t[u],t[v]));
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>n >>q;
    for(int i=1;i<=n;i++) cin>>val[i];    
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0,1);
    top[1]=1;
    hld(1,1);
    for(int i=1;i<=n;i++) con[t[i]]=val[i];
    build(1,n,1);
    while(q--){
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>b >>c;
            update(1,n,1,t[b],c);
        }
        else if(a==2){
            ret=0;
            cin>>b >>c;
            cout<<path(b,c) <<" ";
        }
    }
}
