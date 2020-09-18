#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n,p;
    cin>>n>>p;
    int l1,l2,l3;
    vector<int> value;
    vector<int> magic;
    int sum=0;
    while(n--){
        cin>>l1>>l2>>l3;
        sum+=l1;
        for(int i=0;i<l1;i++){
            value.push_back(l2);
            magic.push_back(l3);
        }
    }

    // cout<<value.size()<<" "<<magic.size()<<endl;
    vector<int> dp;
    for(int i=0;i<p;i++){
        dp.push_back(0);
    }
    for(int i=0;i<sum;i++){
        for(int j=p;j>=0;j--){
            if(value[i]<=j){
                dp[j]=max(dp[j-value[i]]+magic[i],dp[j]);
            }
        }
    }
    cout<<dp[p]<<endl;
}