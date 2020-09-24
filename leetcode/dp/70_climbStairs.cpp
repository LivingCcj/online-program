
#include<iostream>

using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

*/


int climbStairs(int n) {
    
    int c1=1,c2=2;
    for(int i=3;i<=n;i++){
        int tmp;
        tmp=c1+c2;
        c1=c2;
        c2=tmp;
    }
    return c2;
}

int main(){

    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
    return 0;
}