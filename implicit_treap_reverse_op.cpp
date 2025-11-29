#include<bits/stdc++.h>
using namespace std;
//task: https://cses.fi/problemset/result/15436224/
mt19937 mt(time(NULL));
struct node{
    int val,sz,pri;
    bool rev;
    node *l,*r;
};
node *newnode(int key){
    node *tmp=new node;
    *tmp={key,1,mt(),0,NULL,NULL};
    return tmp;
}
int sz(node *tmp){if(tmp==NULL) return 0; return tmp->sz;}
void upd(node *tmp){if(tmp==NULL) return; tmp->sz=sz(tmp->l)+sz(tmp->r)+1;}
void push(node *&tmp){
    if(!tmp || tmp->rev==0) return;
    if(tmp->l) (tmp->l)->rev^=1;
    if(tmp->r) (tmp->r)->rev^=1;
    swap(tmp->l,tmp->r);
    tmp->rev=0;
}
void split(node *t,node *&l,node *&r,int key){
    if(!t) return void(l=r=NULL);
    push(t);
    if(sz(t->l)+1<=key) split(t->r,t->r,r,key-sz(t->l)-1),l=t;
    else split(t->l,l,t->l,key),r=t;
    upd(t);
}
void merge(node *&t,node *l,node *r){
    if(!l) return void(t=r);
    if(!r) return void(t=l);
    push(l),push(r);
    if(l->pri>r->pri) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd(t);
}
void reverse(node *&t,int l,int r){
    node *a,*b,*c;
    split(t,a,b,l-1);
    split(b,b,c,r-l+1);
    b->rev^=1;
    merge(t,a,b);
    merge(t,t,c);
}
void p(node *t){
    push(t);
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
        int a,b;
        cin>>a >>b;
        reverse(t,a,b);
    }
    p(t);
}
