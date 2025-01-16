#include<bits/stdc++.h>
using namespace std;
struct node{
    int val,pri;
    node *l,*r;
};
node *init(int key){
    node *tmp=new node;
    *tmp={key,rand(),NULL,NULL};
    return tmp;
}
void split(node *t,node *&l,node *&r,int k){
    if(!t){
        l=r=NULL;
        return;
    }
    if(t->val<=k) split(t->r,t->r,r,k),l=t;
    else split(t->l,l,t->l,k),r=t;
}
void merge(node *&t,node *l,node *r){
    if(!l) return void(t=r);
    if(!r) return void(t=l);
    if(l->pri>r->pri) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
}
void insert(node *&t,node *it){
    if(!t) return void(t=it);
    if(it->pri>t->pri) split(t,it->l,it->r,it->val),t=it;
    else if(it->val<=t->val) insert(t->l,it);
    else insert(t->r,it);
}
void erase(node *&t,int k){
    if(!t) return;
    if(t->val==k){
        node *tmp=t;
        merge(t,t->l,t->r);
        free(tmp);
    }
    else if(k<=t->val) erase(t->l,k);
    else erase(t->r,k);
}
int main(){
    srand(time(NULL));
}
