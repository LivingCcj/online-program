#include<iostream>



struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){};
    ListNode(int n):val(n),next(nullptr){};
    ListNode(int n,ListNode *nextNode):val(n),next(nextNode){};
};

