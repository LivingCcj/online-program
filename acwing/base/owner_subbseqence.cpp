/*
 * @Description: 是否为子序列 ： https://www.acwing.com/problem/content/2818/
 * 
 * 3 5
子序列：1 3 5
母序列：1 2 3 4 5
 * @Author: ccj
 * @Date: 2020-12-12 17:12:40
 * @LastEditTime: 2020-12-12 17:14:45
 * @LastEditors:  
 */




#include<iostream>

using namespace std;

const int N=100010;

int a[N],b[N];

int main(){
    int m,n;
    
    cin>>m>>n;
    for(int i=0;i<m;i++) cin>>a[i];
    for(int j=0;j<n;j++) cin>>b[j];
    int i=0,j=0;
    for(;i<m && j<n ;){
        if(a[i]==b[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }
    if(i==m){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}