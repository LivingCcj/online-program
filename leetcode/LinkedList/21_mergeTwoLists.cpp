#include<node.h>
#include<iostream>

using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode():val(0),next(nullptr){};
//     ListNode(int n):val(n),next(nullptr){};
//     ListNode(int n,ListNode *nextNode):val(n),next(nextNode){};
// };

ListNode* mergeTwoLists(ListNode *l1,ListNode *l2){
    if(l1==nullptr) return l2;
    if(l2==nullptr) return l1; 
    if(l1->val < l2->val){
        l1->next=mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }
}

int main(){
    ListNode* l4=new ListNode(9,nullptr);
    ListNode* l3=new ListNode(7,l4);
    ListNode* l2=new ListNode(5,l3);
    ListNode* l1=new ListNode(3,l2);

    

    ListNode* s4=new ListNode(20,nullptr);
    ListNode* s3=new ListNode(10,s4);
    ListNode* s2=new ListNode(4,s3);
    ListNode* s1=new ListNode(2,s2);

    ListNode* res=mergeTwoLists(s1,l1);

    while(res!=nullptr){
        cout<<res->val<<endl;
        res=res->next;
    }
    
}