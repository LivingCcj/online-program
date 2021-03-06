#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-subsequence
*/

int longestCommonSubsequence(string text1, string text2) {
    int m=text1.size();
    int n=text2.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                // int a=dp.at(i).at(j-1);
                // int b=dp.at(i-1).at(j);
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];



}


int main(){
    string text1;
    string text2;
    cin>>text1;
    cin>>text2;

    cout<<longestCommonSubsequence(text1,text2)<<endl;
}