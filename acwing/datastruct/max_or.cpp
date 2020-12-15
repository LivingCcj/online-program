/*
 * @Description: 最大异或值 ：https://www.acwing.com/problem/content/145/
 * 
 * 使用前缀树来记录每个数的二进制数
 * 然后最长不同前缀，则表示可以抑或的最大值。
 * 
 * 时间复杂度是O(31*N);
 * @Author: ccj
 * @Date: 2020-12-14 10:37:53
 * @LastEditTime: 2020-12-14 11:13:49
 * @LastEditors:  
 */


#include<iostream>

using namespace std;

typedef long long LL;

const int N =1e5+10,M=31*N;

int son[M][2],idx;


void insert(int n){
    int p=0;
    
    for(int i=30;i>=0;i--){
        int x= n>>i&1;
        if(!son[p][x]) son[p][x]=++idx; //idx表示下个子节点的父节点
        p=son[p][x];  //去记录下一个子节点。
    }
}

int query(int n){
    
    
    int p=0;
    int res=0;
    for(int i=30;i>=0;i--){
        int x = n>>i & 1;
        if(son[p][!x]) {
            res=res*2+!x;  // 左移
            p=son[p][!x];
        }else{
            p=son[p][x];
            res=res*2+x;
        }
    }
    return res;
}



int main(){
    
    int n;
    cin>>n;
    int res=0;
    while(n--){
        int x;
        cin>>x;
        insert(x);  //先插入，再查询，避免了判断空集
        int cot=query(x);
        res=max(res,cot^x);
    }
    cout<<res;
    
    
    return 0;
}