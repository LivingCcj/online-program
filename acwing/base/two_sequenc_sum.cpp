/*
 * @Description:  两个数组的单调性：https://www.acwing.com/problem/content/802/
核心问题：
找到双指针的单调性
时间复杂度：O（m+n）
 * @Author: ccj
 * @Date: 2020-12-12 17:03:53
 * @LastEditTime: 2020-12-12 17:04:57
 * @LastEditors:  
 */



#include<iostream>
using namespace std;

const int N =100010;

int a[N],b[N];

int main(){
    
    int n,m,sum;
    cin>>n>>m>>sum;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];
    
    for(int i=0,j=m-1;i<n && j>=0;){
        if(a[i]+b[j]==sum){
            cout<<i<<" "<<j;
            break;
        }else if (a[i]+b[j]<sum){
            i++;
        }else{
            j--;
        }
    }
    return 0;
}