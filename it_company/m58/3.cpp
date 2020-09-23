#include<bits/stdc++.h>

using namespace std;

// int step[10005][10005];
vector<int> mergerArrays(int* arrayA, int arrayALen, int* arrayB, int arrayBLen) {
    vector<vector<int>> dp(arrayALen+1,vector<int>(arrayBLen+1));
    vector<vector<int>> step(arrayALen+1,vector<int>(arrayBLen+1));
    for(int i=0;i<arrayBLen;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<arrayALen;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<=arrayALen;i++){
        for(int j=1;j<=arrayBLen;j++){
            int tmpA=*(arrayA+i-1);
            int tmpB=*(arrayB+j-1);
            // cout<<tmpA<<" "<<tmpB<<endl;
            if(tmpA==tmpB){
                dp[i][j]=dp[i-1][j-1]+1;
                step[i][j]=1;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    step[i][j]=3;
                }else{
                    dp[i][j]=dp[i][j-1];
                    step[i][j]=2;
                }
            }
        }
    }
    vector<int> res;
    int i=arrayALen;
    int j=arrayBLen;
    while(i>0 && j>0){
        if(step[i][j]==1){
            res.push_back(*(arrayA+i-1));
            i--;
            j--;
        }else if(step[i][j]==2){
            j--;
        }else{
            i--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
//[-5,0,6,8,9,10],[0,8,9,11,15]
int main(){
    int A[]={-5,0,6,8,9,10};
    int B[]={0,8,9,11,15};

    vector<int> res= mergerArrays(A,6,B,5);
    return 0;
   
}