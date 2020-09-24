#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
*/

int minPathSum(vector<vector<int>> & grid){
    int len1=grid.size();
    if(len1==0 || (grid[0].size()==0)){
        return 0;
    }
    int len2=grid[0].size();

    // int* dp=new int[len2];
    vector<int> dp(len2);
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(j==0){  //只能从上面走
                dp[j]=dp[j];
            }else if(i==0){ // 只能从左边走
                dp[j]=dp[j-1];
            }else{
                dp[j]=min(dp[j-1],dp[j]);
            }
            dp[j]=dp[j]+grid[i][j];
        }
        
    }
    
    return dp[len2-1];

}

int main(){
    vector<vector<int>> data;
    for(int i=0;i<5;i++){
        vector<int> d1;
        for(int j=0;j<4;j++){
            d1.push_back(j*3+i+1);
        }
        // for_each(begin(d1),end(d1),[](int x){cout<< x<<" ";});
        // cout<<endl;
        data.push_back(d1);
    }
    vector<vector<int>> data2{{1,3,1},{1,5,1},{4,2,1}};
    // for_each(begin(data2[0]),end(data2[0]),[](int x){cout<<x<<" "<<endl;});
    cout<<minPathSum(data2)<<endl;
}