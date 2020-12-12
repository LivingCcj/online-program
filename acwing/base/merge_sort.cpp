/*
 * @Description: 
 * @Author: ccj
 * @Date: 2020-12-12 16:26:25
 * @LastEditTime: 2020-12-12 16:26:25
 * @LastEditors:  
 */
#include<iostream>

using namespace std;

//题目地址：https://www.acwing.com/problem/content/description/789/
// 两个序列的双指针算法

const int N = 100010;
int p[N],tmp[N];
//归并排序，先分，再合
void merge_sort(int l,int r){
    if(l>=r) return;
    int mid=l+r>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);

    int k=0,i=l,j=mid+1;
    while (i<=mid && j<=r)
    {
        if(p[i]<p[j]) tmp[k++]=p[i++];
        else tmp[k++] = p[j++];
    }
    while(i<=mid) tmp[k++]=p[i++];
    while(j<=r) tmp[k++]=p[j++];
    
    for(int s=0;s<k;s++) p[l+s]=tmp[s];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    merge_sort(0,n-1);
    for(int i=0;i<n;i++) cout<<p[i]<<" ";
    return 0;
}