/*
 * @Description: 反转列表：https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=117&&tqId=23286
 * @Author: ccj
 * @Date: 2020-12-15 14:12:01
 * @LastEditTime: 2020-12-15 14:19:10
 * @LastEditors:  
 */

#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};


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

int main(){
    ListNode *l1(1);
    ListNode *l2(2);
    ListNode *l3(3);
    ListNode *l4(4);
    ListNode *l5(5);
    ListNode *l6(6);

    l1->next=l2;
    l2->next=l3;
    l3->next=l4;

    while(l1){
        cout<<l1->val;
        l1=l1->next;
    }

}
