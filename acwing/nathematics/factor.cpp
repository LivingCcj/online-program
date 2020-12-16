/*
 * @Description: 分解质因数：https://www.acwing.com/problem/content/869/
 * 
 * 
 * 也是试除法。时间复杂度 lgn 到 sqrt(n)
 * 
 * @Author: ccj
 * @Date: 2020-12-16 10:10:45
 * @LastEditTime: 2020-12-16 10:13:16
 * @LastEditors:  
 */



#include<iostream>

using namespace std;

void divide(int n){
    for(int i=2;i<=n/i;i++){  //保证时间复杂度sqrt(n)
        if(n%i==0){     
            int cot=0;
            while(n%i==0){  //保证时间复杂度lg(n) ,比如n=2^k , 同时保证了之前计算的因子都是质数
                n/=i;
                cot++;
            }
            cout<<i<<" "<<cot<<endl;
        }
    }
    if(n>1) cout<<n<<" 1"<<endl;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        divide(m);
        cout<<endl;
    }
    return 0;
}