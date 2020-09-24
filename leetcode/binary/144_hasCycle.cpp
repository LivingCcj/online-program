#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
给定一个链表，判断链表中是否有环。
*/

struct ListNode1
{
    int val;
    ListNode1 *next;
    ListNode1(int x,ListNode1* next1=nullptr):val(x),next(next1){};
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};
// 快慢指针方法 
bool hasCycle(ListNode *head) {
    
    if(head==nullptr) return false;
    ListNode* l1=head;
    ListNode* l2=head->next;
    while( l2!=nullptr && l2->next !=nullptr  && l1!=nullptr){
        if(l1==l2){
            return true;
        }
        l1=l1->next;
        l2=l2->next->next;
    }
    return false;
}


//hash 方法
bool hasCycle1(ListNode *head) {
    unordered_map<ListNode*,int> m;
    while(head){
       m[head]++;
       if(m[head]>1) return true;
       head=head->next;
    }
    return false;
}
int main(){
    vector<int> data{2,3,5,6,1};
    ListNode* head=new ListNode(1);
    ListNode* l1=new ListNode(2);
    ListNode* l2=new ListNode(4);
    ListNode* l3=new ListNode(5);
    ListNode* l4=new ListNode(7);
    head->next=l1;
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l2;
    // for(int a:data){
    //     head=new ListNode(a,head);
    // }
    
    // ListNode* list=head;
    // while(list!=nullptr){
    //     cout<<list->val<<"  "<<endl;
    //     list=list->next;
    // }

    cout<<hasCycle(head)<<endl;
    delete head,l1,l2,l3,l4;
    return 0;
    
}