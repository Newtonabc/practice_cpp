#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
bool visited[N];
vector<pair<int,int> > adj[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int main(){
	int n,m;
	cin>>n >>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a >>b >>c;
		adj[a].push_back(make_pair(c,b));
		adj[b].push_back(make_pair(c,a));
	}
	int sum=0;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int w=q.top().first;
		int u=q.top().second;
		q.pop();
		if(visited[u]) continue;
		else visited[u]=true;
		sum+=w;
		for(int i=0;i<adj[u].size();i++){
			if(!visited[adj[u][i].second]) q.push(adj[u][i]);
		}
	}
	cout<<sum;
}
