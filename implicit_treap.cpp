#include<bits/stdc++.h>
using namespace std;
mt19937 mt(time(NULL));
// task: https://cses.fi/problemset/task/2072
struct node{
    int sz,val,pri;
    node *l,*r;
};
int sz(node *tmp){if(tmp==NULL) return 0; return tmp->sz;}
void upd(node *tmp){if(!tmp) return; tmp->sz=1+sz(tmp->l)+sz(tmp->r);}
node *newnode(int key){
    node *tmp=new node;
    *tmp={1,key,mt(),NULL,NULL};
    return tmp;
}
void split(node *t,node *&l,node *&r,int key){
    if(!t) return void(l=r=NULL);
    if(sz(t->l)+1<=key) split(t->r,t->r,r,key-sz(t->l)-1),l=t;
    else split(t->l,l,t->l,key),r=t;
    upd(t);
}
void merge(node *&t,node *l,node *r){
    if(!l) return void(t=r);
    if(!r) return void(t=l);
    if(l->pri>r->pri) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd(t);
}
void p(node *t){
    if(t->l) p(t->l);
    cout<<(char)(t->val);
    if(t->r) p(t->r);
}
int main(){
    int n,m;
    cin>>n >>m;
    string s;
    cin>>s;
    node *t=NULL;
    for(auto c:s){
        node *tmp=newnode(c);
        merge(t,t,tmp);
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l >>r;
        node *a,*b,*c;
        split(t,a,b,l-1);
        split(b,b,c,r-l+1);
        merge(t,a,c);
        merge(t,t,b);
    }
    p(t);
}
