#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
bool visited[N][N];
queue<pair<int,int> > q;
int main(){
	int a[4]={0,0,1,-1};
	int b[4]={1,-1,0,0};
	/* n,m= table_size
	(st1,st2)= start_floodfill(row,column)*/
	int n,m,st1,st2;
	cin>>n >>m >>st1 >>st2;
	q.push(make_pair(st1,st2));
	visited[st1][st2]=true;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int xa=x+a[i];
			int yb=y+b[i];
			if(xa<0 || xa>=n || yb<0 || yb>=m) continue;
			if(visited[xa][yb]) continue;
			q.push(make_pair(xa,yb));
			visited[xa][yb]=true;
		}
	}
}
