#include<bits/stdc++.h>

using namespace std;


/*
两个字符串合并为一个字符串
aabcc dbbca aadbbcbcac
*/
int main(){
    string str1;
    string str2;
    string str3;
    
    cin>>str1>>str2>>str3;

    int l1=str1.size();
    int l2=str2.size();
    int l3=str3.size();

    if(l1<=0 || l2<=0 || (l1+l2!=l3)){
        cout<<"False"<<endl;
        return 0;
    }
    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));

    dp[0][0]=1;
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if((i-1)>=0 && (dp[i-1][j]==1) && str1[i-1]==str3[i-1+j]){
                dp[i][j]=1;
            }
            if((j-1)>=0 && (dp[i][j-1]==1) && str2[j-1]==str3[i-1+j]){
                dp[i][j]=1;
            }
        }
    }
    if(dp[l1][l2]==1){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}
