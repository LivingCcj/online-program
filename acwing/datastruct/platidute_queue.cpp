/*
 * @Description: 单调队列  ：https://www.acwing.com/problem/content/156/
 * 
 * 针对区间中的最大值或者最小值。
 * 保证队列中的值是单调递增的，这里保存的是下标
 * @Author: ccj
 * @Date: 2020-12-13 20:09:57
 * @LastEditTime: 2020-12-13 20:29:34
 * @LastEditors:  
 */


#include<iostream>
#include<deque>
using namespace std;

const int N =1e6+10;

int a[N],q[N];

int main(){
    int n,k;
    cin>>n>>k;
    deque<int> dd;
    for(int i=0;i<n;i++) cin>>a[i];
    
    for(int i=0;i<n;i++){
        if(!dd.empty() && dd.front()<i-k+1){
            dd.pop_front();
        }
        
        while(!dd.empty() && a[dd.back()]>=a[i]) dd.pop_back();
        dd.push_back(i);
        
        if(i>=k-1) cout<<a[dd.front()]<< " ";
    }
    cout<<endl;
    dd.clear();
    for(int i=0;i<n;i++){
        //保证在查询区间内
        if(!dd.empty() && dd.front()<i-k+1){
            dd.pop_front();
        }
        while (!dd.empty() && a[dd.back()]<=a[i]) dd.pop_back();  //保证单调性

        dd.push_back(i);

        if(i>=k-1) cout<<a[dd.front()]<<" ";
        
    }
    return 0;
}