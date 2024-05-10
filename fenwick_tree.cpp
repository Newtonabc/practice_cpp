#include<bits/stdc++.h>
using namespace std;
//0 break, 1 update idx val, 2 read_sum(1-i) i
const int N=2e5+10;
const int MAXIDX=2e5;
int tree[N];
void update(int idx,int val){
	while(idx<=MAXIDX){
		tree[idx]+=val;
		idx+=idx & -idx;
	}
}
int read(int idx){
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=idx & -idx;
	}
	return sum;
}
int main(){
	int a,b,c;
	while(true){
		cin>>a;
		if(a==0) break;
		else if(a==1){
			cin>>b >>c;
			update(b,c);
		}
		else{
			cin>>b;
			cout<<"sum from 1->" <<b <<"=" <<read(b) <<"\n";
		}
	}
}
