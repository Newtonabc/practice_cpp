#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N],seg[4*N];
void build(int node,int l,int r){
	if(l==r){
		seg[node]=arr[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	seg[node]=min(seg[2*node],seg[2*node+1]);
	return;
}
void update(int node,int idx,int val,int l,int r){
	if(l==r){
		arr[idx]=val;
		seg[node]=val;
		return;
	}
	int mid=(l+r)/2;
	if(idx>=l && idx<=mid){
		update(2*node,idx,val,l,mid);
	}
	else{
		update(2*node+1,idx,val,mid+1,r);
	}
	seg[node]=min(seg[2*node],seg[2*node+1]);
	return;
}
int query(int node,int l,int r,int ql,int qr){
	if(r<ql || l>qr) return INT_MAX;
	if(l>=ql && r<=qr) return seg[node];
	int mid=(l+r)/2;
	int left=query(2*node,l,mid,ql,qr);
	int right=query(2*node+1,mid+1,r,ql,qr);
	return min(left,right);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n >>q;
	for(int i=0;i<n;i++) cin>>arr[i];
	build(1,0,n-1);
	while(q--){
		char op;
		int a,b;
		cin>>op >>a >>b;
		a--,b--;
		if(op=='u'){
			b++;
			update(1,a,b,0,n-1);
		}
		else{
			cout<<query(1,0,n-1,a,b) <<"\n";
		}
	}
}
