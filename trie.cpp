#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int trie[N][30];
bool word[N];
int cnt;
void insert(string s){
    int u=0;
    for(int i=0;i<s.size();i++){
        if(trie[u][s[i]-'a']==0) trie[u][s[i]-'a']=++cnt;
        u=trie[u][s[i]-'a'];
    }
    word[u]=true;
}
bool find(string s){
    int u=0;
    for(int i=0;i<s.size();i++){
        if(trie[u][s[i]-'a']==0) return false;
        u=trie[u][s[i]-'a'];
    }
    return word[u];
}
int main(){
    int n,q;
    cin>>n >>q;
    for(int i=0;i<n;i++){
        string inp;
        cin>>inp;
        insert(inp);
    }
    while(q--){
        string inp;
        cin>>inp;
        cout<<find(inp) <<"\n";
    }
}
