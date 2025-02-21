#include<bits/stdc++.h>
using namespace std;

struct point{
    double x,y;
}; 
vector<point> sortx;

bool comparex(point a,point b){return a.x<b.x;}
bool comparey(point a,point b){return a.y<b.y;}

double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//solve return ans, set of point that sorted by y-coordinate
pair<double,vector<point>> solve(int l,int r){
    if(l==r){
        vector<point> ret;
        ret.push_back(sortx[l]);
        return {LLONG_MAX,ret};
    }
    int mid=(l+r)/2;
    auto [ansl,vl]=solve(l,mid);
    auto [ansr,vr]=solve(mid+1,r);
    int n=vl.size(),m=vr.size(),indl=0,indr=0;
    double ans=min(ansl,ansr);
    vector<point> v;
    //make v be the vector of point sort by y
    while(indl<n && indr<m){
        if(vl[indl].y<vr[indr].y) v.push_back(vl[indl]),indl++;
        else v.push_back(vr[indr]),indr++;
    }
    while(indl<n) v.push_back(vl[indl]),indl++;
    while(indr<m) v.push_back(vr[indr]),indr++;
    //create strip that element same as v but has x-coor dif from mid less than ans
    vector<point> strip;
    double xmid=sortx[mid].x;
    for(auto p:v){
        if(abs(p.x-xmid)>ans) continue;
        strip.push_back(p);
    }
    for(int i=0;i<strip.size();i++){
        for(int j=1;j<=7;j++){
            if(i+j<strip.size()) ans=min(ans,dist(strip[i],strip[i+j]));
        }
    }
    return {ans,v};
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        point tmp;
        cin>>tmp.x >>tmp.y;
        sortx.push_back(tmp);
    }
    sort(sortx.begin(),sortx.end(),comparex);
    auto [ans,tmp]=solve(0,n-1);
    cout<<ans;
}
