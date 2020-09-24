#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*

给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
*/


class NumArray{
    public:
        NumArray(vector<int> &nums){
            data.resize(nums.size()+1);
            for(int i=1;i<=nums.size();i++){
                data[i]=data[i-1]+nums[i-1];
            }
        }
        int sumRange(int i,int j){
            return data[j+1]-data[i];
        }   

    public:
        vector<int> data;
};

int main(){
    vector<int> test{-1,4,6,1,-12,9,19};
    NumArray* num=new NumArray(test);
    for_each(begin(num->data),end(num->data),[](int x){cout<<x<<" ";});
    cout<<num->sumRange(2,6)<<endl;
}