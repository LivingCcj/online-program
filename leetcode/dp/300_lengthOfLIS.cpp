#include<iostream>
#include<vector>

using namespace std;

const int N=100050;
int a[N];
int res[N];
int n;

int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len==0){
            return 0;
        }

        vector<int> data(len,1);
        int ans=1;
        for(int i=0;i<len;i++){
            cout<<nums[i]<<endl;
            for(int j=0;j<i;j++){
                
                if(nums[j]<nums[i]){
                    data[i]=max(data[i],data[j]+1);
                    cout<<"m"<<endl;
                }
            }
            ans=max(ans,data[i]);
        }
        return ans;
    }

int main(){
    // cin>>n;
    // for(int i=1;i<=n;i++) cin>>a[i];
    // int ans=1;
    // for(int i=1;i<=n;i++){
    //     res[i]=1;
    //     for(int j=1;j<i;j++){
    //         if(a[j]<a[i]){
    //             res[i]=max(res[i],res[j]+1);
    //         }
    //     }
    //     cout<<res[i]<<endl;
    //     ans=max(res[i],ans);
    // }
    // cout<<ans<<endl;
    vector<int> data={-2,-1};
    cout<<lengthOfLIS(data)<<endl;
    return 0;
}