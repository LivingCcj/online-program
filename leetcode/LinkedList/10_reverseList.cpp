#include<iostream>
#include<node.h>

using namespace std;
//头插法反转整个list
ListNode *reverseList(ListNode *l1){

    ListNode *newNode=new ListNode(-1,nullptr);
    while(l1!=nullptr){
        ListNode* tmp=l1->next; //record next node
        l1->next=newNode->next;
        newNode->next=l1;
        l1=tmp;
    }
    return newNode->next;

}

//递归方式的反转list
ListNode *reverseList1(ListNode *head){
    if(head ==nullptr && head->next==nullptr)
    {
        return head;
    }
    ListNode *next =head.next;
    ListNode *newNode=reverseList1(next);
    next.next=head;
    head=nullptr;
    return newNode;

}
//反转n-m的list
ListNode *reverseList(ListNode *l1,int k){

    ListNode *newNode=new ListNode(-1,nullptr);
    while(l1!=nullptr){
        ListNode* tmp=l1->next; //record next node
        l1->next=newNode->next;
        newNode->next=l1;
        l1=tmp;
    }
    return newNode->next;

}

int main(){
    ListNode* l5=new ListNode(15,nullptr);
    ListNode* l4=new ListNode(9,l5);
    ListNode* l3=new ListNode(7,l4);
    ListNode* l2=new ListNode(5,l3);
    ListNode* l1=new ListNode(3,l2);

    ListNode * res=reverseList(l1);

    while(res!=nullptr){
        cout<<res->val<<endl;
        res=res->next;
    }

    int n=2,m=4;
    ListNode * res1=l1;
    int index;
    ListNode *tmp;
    while(res1!=null){
        
        if(index==n-1){
            tmp=res1;
        }
        if(index<n){
            index++;
            res1=re1->next;
            continue;
        }
        if(index>=n && index <m){
            tmp->next=reverseList(res1,n-m+1);
            index+=n-m+1;

        }
        if(index>m){
            res1
        }
    }

}