#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
int pa[N];
int root(int x){
	if(pa[x]==x) return x;
	else return pa[x]=root(pa[x]);
}
int main(){
	int n,m;
	cin>>n >>m;
	for(int i=0;i<=n;i++) pa[i]=i;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a >>b >>c;
		q.push(make_pair(c,make_pair(a,b)));
	}
	int sum=0;
	while(!q.empty()){
		int w=q.top().first;
		int u=q.top().second.first;
		int v=q.top().second.second;
		q.pop();
		if(root(u)==root(v)) continue;
		sum+=w;
		pa[root(u)]=root(v);
	}
	cout<<sum;
}
