/*
 * @Description: 查找第一个大于等于查找值得位置 ：
 * @Author: ccj
 * @Date: 2020-12-15 14:31:39
 * @LastEditTime: 2020-12-15 14:44:19
 * @LastEditors:  
 */


#include<iostream>
#include<vector>
using namespace std;

int upper_bound(int n,int m,vector<int> &arr){
    int l=0,r=n-1;
    if(m<arr[0] || m>arr[n-1]){
        return n+1;
    }
    while(l<r){
        int mid=(l+r)>>1;
        if(arr[mid]<m) l=mid+1;
        else r=mid;
    }
    return l+1;
}

int main(){
    vector<int> data{1,2,4,4,5};
    int n,m;
    cin>>n>>m;

    cout<<upper_bound(n,m,data)<<endl;
    return 0;
}