//andrew monotone chain
#include<bits/stdc++.h>
using namespace std;
struct point{
    double x,y;
};
double cross(point a,point b,point c){
    return (c.y-a.y)*(b.x-a.x)-(c.x-a.x)*(b.y-a.y);
}
bool cmp(point &a,point &b){
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
int main(){
    int n;
    cin>>n;
    vector<point> v,up,down;
    for(int i=0;i<n;i++){
        point tmp;
        cin>>tmp.x >>tmp.y;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp);
    point l=v[0],r=v[v.size()-1];
    up.push_back(l),down.push_back(l);
    for(int i=1;i<v.size();i++){
        double side=cross(l,r,v[i]);
        if(side>=0){
            while(up.size()>=2 && cross(up[up.size()-2],up[up.size()-1],v[i])>0) up.pop_back();
            up.push_back(v[i]);
        }
        if(side<=0){
            while(down.size()>=2 && cross(down[down.size()-2],down[down.size()-1],v[i])<0) down.pop_back();
            down.push_back(v[i]);
        }
    }
    v.clear();
    for(int i=0;i<up.size();i++) v.push_back(up[i]);
    for(int i=down.size()-2;i>0;i--) v.push_back(down[i]);
    cout<<v.size() <<"\n";
    for(auto p:v){
        cout<<(int)p.x <<" " <<(int)p.y <<"\n";
    }
}
