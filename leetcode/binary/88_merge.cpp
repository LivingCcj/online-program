#include<iostream>
#include<vector>
using namespace std;
/*
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index1=m-1;
    int index2=n-1;
    int index=m+n-2;

    while(index1>=0 || index2>=0){
        if(index1<0){
            nums1[index--]=nums2[index2--];
        } else if(index2<0){
            nums1[index--]=nums1[index1--];
        } else if(nums1[index1]>nums2[index2]){
            nums1[index--]=nums1[index1--];
        }else{
            nums1[index--]=nums2[index2--];
        }
    }
}


int main(){
    vector<int> n1{1,2,3,0,0,0};
    vector<int> n2{2,5,6};
    merge(n1,6,n2,3);
    for(int a:n1){
        cout<<a<<endl;
    }

}