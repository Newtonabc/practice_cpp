#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int dp[N];
int main(){
	//arr[0]=0
	int arr[]={0,2,1,3,2,14,5,2,-2,3};
	int n=9;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+arr[i];
	}
	for(int i=0;i<=n;i++) cout<<dp[i] <<" ";
}
