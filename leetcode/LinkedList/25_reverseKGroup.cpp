#include<iostream>
#include<node.h>

using namespace std;

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *newNode=new ListNode(-1);
    ListNode *tmp;
    ListNode *tNode=head;
    while(k--){
        tmp=head->next;
        head->next=newNode->next;
        newNode->next=head;
        head=tmp;
    }
    tNode->next=head;
    return newNode->next;
}


// ListNode* reverseKGroup(ListNode* head, int k) {
//     ListNode *newNode=new ListNode(-1);
    
//     ListNode *tmp=head;
//     int N=0;
//     while(tmp){
//         N++;
//         tmp=tmp->next;
//     }
//     ListNode  *first;
//     ListNode *tNode;
//     for(int j=k;j<=N;){
//         tNode=head;
//         for(int i=0;i<k;i++){
            
//             tmp=head->next;
//             head->next=newNode->next;
//             newNode->next=head;
//             head=tmp;
//         }
//         if(j==k) first=newNode->next;
//         tNode->next=head;
//         j+=k;
//     }
//     return first;
// }

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
    ListNode *tmp=reverseKGroup(v1,8);
    while(tmp){
        cout<<tmp->val<<endl;
        tmp=tmp->next;
    }
}