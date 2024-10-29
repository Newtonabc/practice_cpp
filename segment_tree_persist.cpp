#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=(1<<19)+4e6;
int root[N],cnt;
long long arr[N];
struct node{
    int l,r;
    long long val;
}tree[M];
int clone(int idx){tree[++cnt]=tree[idx]; return cnt;}
void build(int l,int r,int idx){
    cnt=max(cnt,idx);
    if(l==r){tree[idx]={0,0,arr[l]}; return;}
    int m=(l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    tree[idx].l=idx*2,tree[idx].r=idx*2+1;
    tree[idx].val=tree[idx*2].val+tree[idx*2+1].val;
}
int update(int l,int r,int idx,int a,int b){
    int now=clone(idx);
    if(l==r){
        tree[now].val=b;
        return now;
    }
    int m=(l+r)/2;
    if(a<=m) tree[now].l=update(l,m,tree[idx].l,a,b);
    else tree[now].r=update(m+1,r,tree[idx].r,a,b);
    tree[now].val=tree[tree[now].l].val+tree[tree[now].r].val;
    return now;
}
long long query(int l,int r,int idx,int a,int b){
    if(a>r || b<l) return 0;
    if(a<=l && b>=r) return tree[idx].val;
    int m=(l+r)/2;
    return query(l,m,tree[idx].l,a,b)+query(m+1,r,tree[idx].r,a,b);
}
int main(){
    int n,q,cp=1;
    cin>>n >>q;
    root[1]=1;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,n,1);
    while(q--){
        int a,b,c,d;
        cin>>a;
        if(a==1){
            cin>>b >>c >>d;
            root[b]=update(1,n,root[b],c,d);
        }
        else if(a==2){
            cin>>b >>c >>d;
            cout<<query(1,n,root[b],c,d) <<"\n";
        }
        else{
            cin>>b;
            root[++cp]=root[b];
        }
    }
}
