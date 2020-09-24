#include<iostream>
#include<vector>
#include<algorithm>
/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
*/

using namespace std;
// 时间内复杂度 O(N) 空间复杂度O(N)
int rob(vector<int> &nums)
{

    int len = nums.size();
    if (len == 0)
    {
        return 0;
    }
    else if (len == 1)
    {
        return nums[0];
    }
    else if (len == 2)
    {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    else
    {
        vector<int> money;
        int max;
        money.push_back(nums[0]);
        money.push_back(nums[1]);
        max=nums[0]>nums[1]?nums[0]:nums[1];
        for (int i = 2; i < len; i++)
        {
            auto it = max_element(money.begin(), money.begin() + i - 1);
            int cur = *it + nums[i];
            if(max<cur){
                max=cur;
            }
            money.push_back(cur);
        }
        return max;
    }
}
// 时间内复杂度 O(N) 空间复杂度O(1)

int rob2(vector<int> &nums)
{

    int len = nums.size();
    if (len == 0)
    {
        return 0;
    }
    else if (len == 1)
    {
        return nums[0];
    }
    else 
    {
        
        int pre1=0,pre2=0;
        for(int i=0;i<nums.size();i++){
            
            int tmp=max(pre1,pre2+nums[i]);
            //pre2 存在滞后
            pre2=pre1;
            pre1=tmp;
            
        }
        return pre1;
    }
    
}
int main(){
    vector<int> nerb{1  ,3, 4,3};
    cout<<rob2(nerb)<<endl;
    return 0;
}