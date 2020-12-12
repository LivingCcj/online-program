/*
 * @Description: 数值很大，离散化，：https://www.acwing.com/problem/content/description/804/
 * 区间和问题
 * @Author: ccj
 * @Date: 2020-12-12 20:31:15
 * @LastEditTime: 2020-12-12 20:33:38
 * @LastEditors:  
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N=300010;

typedef pair<int,int> PII;
int a[N],s[N];

vector<int> all;
vector<PII> add,query;

int find(int x){
    int i=0,j=all.size()-1;
    while(i<j){
        int mid=(i+j)>>1;
        if(all[mid]>=x) j=mid;
        else i=mid+1;
    }
    return j+1;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    PII tmp;
    for(int i=0;i<n;i++){
        cin>>tmp.first>>tmp.second;
        add.push_back(tmp);
        all.push_back(tmp.first);
    }
    
    for(int j=0;j<m;j++){
        cin>>tmp.first>>tmp.second;
        query.push_back(tmp);
        all.push_back(tmp.first);
        all.push_back(tmp.second);
    }
    //删去重复的元素，避免重复映射
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    
    //更新插入的数值，同时映射到坐标中
    for(auto item:add){
        int x=find(item.first);
        a[x]+=item.second;
    }
    //前缀和
    for(int i=1;i<=all.size();i++) s[i]=s[i-1]+a[i];
    //查询结果
    for(auto item:query){
        int l=find(item.first);
        int r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    
    return 0;
    
}