/*
 * @Description: 最长公共子序列：https://www.acwing.com/problem/content/899/
 * 
 * 状态表示dp[i][j] a前i个字符和b前j个字符的公共子序列个数
 * 属性：最长公共子序列个数
 * 状态转换：dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1) or dp[i][j]=max(dp[i-1][j],dp[i][j-1])
 * @Author: ccj
 * @Date: 2020-12-15 20:48:15
 * @LastEditTime: 2020-12-15 20:55:52
 * @LastEditors:  
 */




#include<iostream>

using namespace std;

const int N =1010;
int dp[N][N];

char str1[N],str2[N];

int main(){
    int n,m;
    cin>>n>>m>>str1+1>>str2+1;
    for(int i=1;i<=n;i++ ){
        for(int j=1;j<=m;j++){
            if(str1[i]==str2[j]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    cout<<dp[n][m];
    return 0;
}
