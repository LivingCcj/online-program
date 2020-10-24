#include<iostream>
#include<node.h>
using namespace std;


bool hasCycle(ListNode *head) {
        ListNode *next1=head->next;
        while(head!=nullptr && next1!=nullptr && next1->next !=nullptr ){
            if(head==next1) {
                cout<<head->val<<endl;
                return true;
            }
            head=head->next;
            next1=next1->next->next;
        }
        return false;
    }
//找到相交的点
ListNode* CycleAt(ListNode * head){
    ListNode *low=head;
    ListNode *fast=head;

    while(low!=nullptr && fast !=nullptr && fast->next !=nullptr){
        low=low->next;
        fast = fast->next->next;
        if(low == fast){
            break;
        }
    }
    if(fast !=nullptr && low != nullptr){
        ListNode *tmp=head;
        while(tmp!=fast){
            tmp = tmp->next;
            fast = fast->next;
        }
    }
    return fast;
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
    v6->next=v3;
    cout<<hasCycle(v1)<<endl;
    ListNode * node=CycleAt(v1);
    cout<<node->val<<endl;
}