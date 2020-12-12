/*
 * @Description: 区间合并：https://www.acwing.com/problem/content/805/

核心问题，考虑好三个情况
 * @Author: ccj
 * @Date: 2020-12-12 20:57:02
 * @LastEditTime: 2020-12-12 20:58:05
 * @LastEditors:  
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


typedef pair<int,int> PII;


int merge(vector<PII> &segs){
    int res=0;
    //区间左排序
    sort(segs.begin(),segs.end());
    int l=-2e9,r=-2e9;
    for(auto item:segs){
        if(r<item.first){
            res++;
            l=item.first;
            r=item.second;
        }else{
            r=max(r,item.second);
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    PII tmp;
    vector<PII> segs;
    
    while(n--){
        cin>>tmp.first>>tmp.second;
        segs.push_back(tmp);
    }
    
    cout<<merge(segs);
    return 0;
}