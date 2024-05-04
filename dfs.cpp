#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int> adj[N];
bool visited[N];
void dfs(int u){
	if(visited[u]) return;
	visited[u]=true;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!visited[v]) dfs(v);
	}
}
int main(){
	int n,m;
	cin>>n >>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a >>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}
