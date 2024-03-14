#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[]={1,1,2,2,2,3,4,4,4,4,5,6};
	int fd=2;
	int l=0,r=11,mid;
	while(l<r){
		mid=(l+r)/2;
		if(arr[mid]>=fd) r=mid;
		else l=mid+1;
	}
	cout<<l;
}
