
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/
//大顶堆
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> que;
    for(int n:nums){
        if(que.size()<k){
            que.push(n);
        }else{
            que.push(n);
            que.pop();
        }
    }
    return que.top();
}

//基于快排的思想
void swapij(vector<int> &data,int i,int j){
    int tmp=data[i];
    data[i]=data[j];
    data[j]=tmp;
}
int Sort(vector<int>& data,int l,int r){
    int tmp=data[l];
    int i=l;
    for(int j=l+1;j<=r;j++){
        if(data[j]<tmp){
            i++;
            swapij(data,i,j);
        }
    }
    swapij(data,l,i);
    return i;
}

int partialSort(vector<int>& data,int l,int r,int index){

    int cur=Sort(data,l,r);
    if(cur==index){
        return data[cur];
    }else if(cur<index){
        return partialSort(data,cur+1,r,index);
    }else{
        return partialSort(data,l,cur-1,index);
    }
} 

int findKthLargest_quick(vector<int>& nums, int k) {
    int len=nums.size();
    int minK=len-k;
    return partialSort(nums,0,len-1,minK);
}

int main(){
    vector<int> vec{3,5,1,5,3,10,8};
    cout<<findKthLargest_quick(vec,5)<<endl;
} 