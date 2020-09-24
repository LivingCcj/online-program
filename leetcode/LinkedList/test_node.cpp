#include<node.h>
#include<iostream>

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(head==nullptr) return nullptr;
        ListNode *tmp=head;
        while(tmp!=nullptr){
            if(tmp->next!=nullptr && tmp->val==(tmp->next->val)){
                ListNode *p =tmp->next;
                tmp->next=tmp->next->next;
                delete p;
            }else{
                tmp=tmp->next;
            }
        }
        return head;
    }

int main(){
    ListNode *v1=new ListNode(1);
    ListNode *v2=new ListNode(1);
    v1->next=v2;

    ListNode *tmp=deleteDuplicates(v1);

    while(tmp){
        cout<<tmp->val<<endl;
        tmp=tmp->next;
    }
}