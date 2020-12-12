/*
 * @Description: 前缀和，https://www.acwing.com/problem/content/797/
 * @Author:  ccj
 * @Date: 2020-12-12 11:08:01
 * @LastEditTime: 2020-12-12 11:15:34
 * @LastEditors:  
 */

#include<iostream>

using namespace std;

const int N = 100010;

int p[N];


int main(){
    int n,k;
    cin>>n>>k;
    int tmp;
    p[0]=0;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        p[i]=p[i-1]+tmp;
    }
    
    
    while(k--){
        int l,r;
        cin>>l>>r;
        int res=p[r]-p[l-1];
        cout<<res<<endl;
    }
    return 0;    
}
