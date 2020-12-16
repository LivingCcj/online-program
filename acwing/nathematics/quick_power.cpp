/*
 * @Description: 快速幂 :https://www.acwing.com/problem/content/877/
 * @Author: ccj
 * @Date: 2020-12-16 10:57:19
 * @LastEditTime: 2020-12-16 10:58:20
 * @LastEditors:  
 */

#include<iostream>

using namespace std;

typedef long long LL;
int main(){
    int n;
    cin>>n;
    int a,b,p;
    while(n--){
        cin>>a>>b>>p;
        LL res=1;
        while(b){
            if(b&1) res=(LL)res*a %p;  //当b&1 ==1时，积累乘积。注意类型转换，同时mod p
            b>>=1;
            a=(LL)a*a % p;
        }
        cout<<res<<endl;
    }
    return 0;
}