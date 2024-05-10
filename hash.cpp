#include<bits/stdc++.h>
using namespace std;
//hash int to int
//0=break,1=add key value,2=find value from key
const int HASH=2e5+3;
pair<int,int> tb[HASH];
int main(){
	bool f;
	int a,b,c,idx,cl,mxcl=0;
	while(true){
		cin>>a;
		if(a==0) break;
		else if(a==1){
			cin>>b >>c;
			idx=b%HASH;
			cl=0;
			while(true){
				if(tb[idx].first==0 && tb[idx].second==0) break;
				cl++;
				idx++;
				idx%=HASH;
			}
			tb[idx]=make_pair(b,c);
			mxcl=max(mxcl,cl);
		}
		else{
			cin>>b;
			f=false;
			idx=b%HASH;
			cl=0;
			while(true){
				if(tb[idx].first==b){
					f=true;
					cout<<b <<"=" <<tb[idx].second <<"\n";
					break;
				}
				cl++;
				idx++;
				idx%=HASH;
				if(cl>mxcl) break;
			}
			if(!f) cout<<"Not found\n";
		}
	}
	
}
