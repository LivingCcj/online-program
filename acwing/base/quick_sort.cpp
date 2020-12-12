/*
 * @Description: 
 * @Author: ccj
 * @Date: 2020-12-12 16:27:52
 * @LastEditTime: 2020-12-12 16:27:52
 * @LastEditors:  
 */
#include<iostream>

using namespace std;
const int N = 100010;
int q[N];

//地址：https://www.acwing.com/problem/content/787/
//快排，双指针算法

//注意边界条件
void quick_sort(int q[], int l, int r){
    if(l>=r) return ;
    
    int x = q[l+r>>1],i=l,j=r;
    while(1){
        while(q[i]<x) i++;
        while(q[j]>x) j--;
        if(i>=j) break; 
        swap(q[i],q[j]);
        i++;
        j--;
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main(){
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    
    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",q[i]);
    return 0;
}