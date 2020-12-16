/*
 * @Description: 最长上升子序列： https://www.acwing.com/problem/content/897/
 * 
 * 
 * 状态表示；dp[i]表示第i个数结尾，最大的上升子序列之和
 * 状态属性：最大的上升子序列个数之和
 * 状态转移方程: for(j=0...i-1) f[i]=max(dp[i],dp[j]+1)
 * 时间复杂度 o(N^2)
 * @Author: ccj
 * @Date: 2020-12-15 20:10:38
 * @LastEditTime: 2020-12-15 20:14:03
 * @LastEditors:  
 */
#include<iostream>

using namespace std;
const int N =1010;

int dp[N];
int a[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=1;i<=n;i++){
        dp[i]=1;  //初始状态为：1
        for(int j=0;j<=i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],dp[j]+1); 
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dp[i]);
    
    cout<<res;
    return 0;
}