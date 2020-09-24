#include<iostream>
#include<vector>

using namespace std;

/*
参考198-打家劫舍题目
这是一次循环数。

*/

int rob2(vector<int> &nums,int first,int last)
{

    int pre1 = 0, pre2 = 0;
    for (int i = first; i <=last; i++)
    {

        int tmp = max(pre1, pre2 + nums[i]);
        //pre2 存在滞后
        pre2 = pre1;
        pre1 = tmp;
    }
    return pre1;
}

int rob(vector<int>& nums){
    int len=nums.size();
    if(len==0){
        return 0;
    }else if(len==1){
        return nums[0];
    }else{
        return max(rob2(nums,0,len-2),rob2(nums,1,len-1));
    }
}

int main(){
    vector<int> nerb{1  ,3, 4,3};
    cout<<rob(nerb)<<endl;
    return 0;
}