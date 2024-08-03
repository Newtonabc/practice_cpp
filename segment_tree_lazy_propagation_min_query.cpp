#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1<<18;
int arr[N],s[M*2],lz[M*2];

void pushlz(int l,int r,int idx){
	if(!lz[idx]) return;
	s[idx]+=lz[idx];
	if(l!=r) lz[idx*2]+=lz[idx],lz[idx*2+1]+=lz[idx];
	lz[idx]=0;
}

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

void update(int l,int r,int idx,int a,int b,int val){
	if(b<l || a>r) return;
	pushlz(l,r,idx);
	if(a<=l && b>=r){
		lz[idx]+=val;
		pushlz(l,r,idx);
		return;
	}
	int m=(l+r)/2;
	update(l,m,idx*2,a,b,val);
	update(m+1,r,idx*2+1,a,b,val);
	s[idx]=min(s[idx*2],s[idx*2+1]);
}

int query(int l,int r,int idx,int a,int b){
	if(b<l || a>r) return INT_MAX;
	pushlz(l,r,idx);
	if(a<=l && b>=r) return s[idx];
	int m=(l+r)/2;
	return min(query(l,m,idx*2,a,b),query(m+1,r,idx*2+1,a,b));
}
