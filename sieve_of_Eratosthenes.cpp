#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool prime[N];
int main(){
	int n,cnt=0;
	cin>>n;
	for(int i=2;i<=n;i++) prime[i]=true;
	for(int i=2;i*i<=n;i++){
		if(prime[i]){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(prime[i]) cnt++,cout<<i <<" ";
	}
	cout<<"\n";
	cout<<cnt;
}
