#include<iostream>
#include<vector>

using namespace std;
/**
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
**/
vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int len=numbers.size();
        int front=0;
        int last=len-1;
        for(;front<last;){
            int sum=numbers[front]+numbers[last];
            if(sum == target){
                res.push_back(front);
                res.push_back(last);
                return res;
                // return vector<int>{front+1,last+1};
            }
            if(sum<target){
                front++;
            }else{
                last--;
            }
        }
        return vector<int>{-1,-1};
        
}


int main(){
    int target=22;
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(14);
    numbers.push_back(29);
    vector<int> res;
    res=twoSum(numbers,target);
    for(int a:res){
        cout<<a<<endl;
    }
    return 0;
}
