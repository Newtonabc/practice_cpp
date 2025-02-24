//problem: https://atcoder.jp/contests/dp/tasks/dp_z
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll dp[N],h[N];
struct convexhull{
    struct line{
        ll m,c;
        line(ll m,ll c):m(m),c(c){}
        ll val(ll x){return m*x+c;}
        double intersect(const line &l){
            return (double)(l.c-c)/(double)(m-l.m);
        }
    };
    bool bad(line a,line b,line c){
        return a.intersect(c)<=a.intersect(b);
    }
    deque<line> hull;
    void add(long long m,long long c){
        line l(m,c);
        while(hull.size()>1 && bad(l,hull.end()[-2],hull.back())) hull.pop_back();
        hull.push_back(l);
    }
    ll query(ll x){
        while(hull.size()>1 && hull[1].val(x)<=hull[0].val(x)) hull.pop_front();
        return hull[0].val(x);
    }
};
int main(){
    int n;
    ll c;
    cin>>n >>c;
    for(int i=1;i<=n;i++) cin>>h[i];
    convexhull cht;
    dp[1]=0;
    cht.add(-2LL*h[1],h[1]*h[1]);
    for(int i=2;i<=n;i++){
        dp[i]=cht.query(h[i])+h[i]*h[i]+c;
        cht.add(-2LL*h[i],h[i]*h[i]+dp[i]);
    }
    cout<<dp[n];
}
