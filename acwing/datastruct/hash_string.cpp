/*
 * @Description: 哈希字符串 ： https://www.acwing.com/problem/content/843/
 * 核心1：利用字符串前缀hash
 * 核心2：区域字符串hash计算
 * @Author: ccj
 * @Date: 2020-12-14 14:45:05
 * @LastEditTime: 2020-12-14 15:05:01
 * @LastEditors:  
 */


#include<iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5+10,P=131;


char s[N];
ULL p[N],h[N];

//获取[L，R]之间的字符串对应的hash值
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}

int main(){
    int n,m;
    cin>>n>>m>>s+1;
    
    p[0]=1;
    //计算string的前缀hash值
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+s[i];
    }
    
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        ULL hash1=get(l1,r1);
        ULL hash2=get(l2,r2);
        if(hash1==hash2){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}