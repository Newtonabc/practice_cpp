#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int pa[N];
int root(int x){
	if(pa[x]==x) return x;
	else return pa[x]=root(pa[x]);
}
int main(){
	int u,v;
	cin>>u >>v;
	
	//make u,v to same component
	pa[root(u)]=root(v);
	
	//check if u,v same component or not
	if(root(u)==root(v)){
		//same component
	}
}
