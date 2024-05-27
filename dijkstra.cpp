#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<pair<int,int> > adj[N];
int dist[N];
bool vs[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int main(){
	int n,m;
	cin>>n >>m;
	for(int i=0;i<=n;i++) dist[i]=INT_MAX;
	dist[1]=0;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a >>b >>c;
		adj[a].push_back(make_pair(c,b));
		adj[b].push_back(make_pair(c,a));
	}
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vs[u]) continue;
		vs[u]=true;
		for(int i=0;i<adj[u].size();i++){
			int w=adj[u][i].first;
			int v=adj[u][i].second;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v],v));
			}
		}
	}
	cout<<dist[n];
}
