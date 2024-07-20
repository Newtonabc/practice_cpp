#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1<<18;
int s[M*2],arr[N];

void build(int l,int r,int idx){
	if(l==r){
		s[idx]=arr[l];
		return;
	}
	int m=(l+r)/2;
	build(l,m,idx*2);
	build(m+1,r,idx*2+1);
	s[idx]=min(s[idx*2],s[idx*2+1]);
}

void update(int l,int r,int idx,int x,int val){
	if(x<l || x>r) return;
	if(l==r){
		s[idx]=val;
		return;
	}
	int m=(l+r)/2;
	update(l,m,idx*2,x,val);
	update(m+1,r,idx*2+1,x,val);
	s[idx]=min(s[idx*2],s[idx*2+1]);
}

int query(int l,int r,int idx,int a,int b){
	if(b<l || a>r) return INT_MAX;
	if(a<=l && b>=r) return s[idx];
	int m=(l+r)/2;
	return min(query(l,m,idx*2,a,b),query(m+1,r,idx*2+1,a,b));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n >>q;
	for(int i=1;i<=n;i++) cin>>arr[i];
	build(1,n,1);
	while(q--){
		int a,b,c;
		cin>>a >>b >>c;
		if(a==1) update(1,n,1,b,c);
		else cout<<query(1,n,1,b,c) <<"\n";
	}
}
