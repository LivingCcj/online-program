#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};

};

ListNode * reverseBetween(ListNode* head,int m,int n){

    ListNode * newhead=new ListNode(0);
    newhead->next=head;
    ListNode *pre;
    pre=newhead;
    for(int i=1;i<m;i++){
        pre=pre->next;
    }
    ListNode *cur=pre->next,*mNext=pre->next;
    //头插法
    for(int i=m;i<=n;i++){
        ListNode* tmp=cur->next;
        cur->next=pre->next;
        pre->next=cur;
        cur=tmp;
    }
    mNext->next=cur;
    return newhead->next;

}

ListNode * reverseBetween1(ListNode* head,int m,int n){

   ListNode *pre,*curr;
   pre=nullptr;
   curr=head;
   while(m>1){
       pre=curr;
       curr=curr->next;
       m--;
       n--;
   }
   ListNode *after=curr,*before=pre;
   while(n>0){
       ListNode *next=curr->next;
       curr->next=pre;
       pre=curr;
       curr=next;
       n--;
   }
   if(before) before->next=pre;
   else head=pre;   //前段连接

   after->next=curr; //后段连接
   return head;

}
int main(){

    ListNode* v1=new ListNode(1);
    ListNode* v2=new ListNode(2);
    ListNode* v3=new ListNode(3);
    ListNode* v4=new ListNode(4);
    ListNode* v5=new ListNode(5);
    ListNode* v6=new ListNode(6);
    v1->next=v2;
    v2->next=v3;
    v3->next=v4;
    v4->next=v5;
    v5->next=v6;

    ListNode* s1=new ListNode(3);
    ListNode* s2=new ListNode(5);
    s1->next=s2;
    ListNode *tmp=s1;
    while(tmp){
        cout<<tmp->val<<endl;
        tmp=tmp->next;
    }

    tmp=reverseBetween(s1,1,2);

    while(tmp){
        cout<<tmp->val<<endl;
        tmp=tmp->next;
    }
}