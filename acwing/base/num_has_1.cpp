/*
 * @Description: 数中1的个数：https://www.acwing.com/problem/content/803/
 * @Author: ccj
 * @Date: 2020-12-12 17:19:35
 * @LastEditTime: 2020-12-12 17:20:07
 * @LastEditors:  
 */




#include<iostream>

using namespace std;

const int N =100010;

int a[N];

//获取1的个数
int getBin(int n){
    int res=0;
    while(n!=0){
        if(n&1){
            res++;
        }
        n>>=1;
    }
    return res;
}


int main(){
    int n;
    cin>>n;
    
    int tmp;
    for(int i=0;i<n;i++) {
        cin>>tmp;
        cout<<getBin(tmp)<<" ";
    }
    return 0;
    
}
