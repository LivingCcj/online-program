#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int ww[100005];
int vv[100005];
int main(){
    int K,N;
    cin>>K>>N;
    int tmp;
    for(int i=0;i<N;i++){
        cin>>ww[i];
    }
    for(int i=0;i<N;i++){
        cin>>vv[i];
    }
    vector<int> dp(K+1,0);
    for(int i=0;i<N;i++){
        // cout<<ww[i]<< " "<<vv[i]<<endl;
        for(int j=K;j>=ww[i];j--){
            dp[j]=max(dp[j],dp[j-ww[i]]+vv[i]);
        }
    }
    cout<<dp[K]<<endl;
    return 0;
}