#include<iostream>
#include<math.h>
using namespace std;

/*
leetcode 633
level: easy
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。
*/
typedef long long LL;
bool judge(int c){
    LL i=0;
    LL j=(LL)sqrt(c);
    for(;i<=j;){
        LL sum=i*i+j*j;
        if(sum==c){
            return true;
        }
        if(sum>c){
            j--;
        }else{
            i++;
        }
    }
    return false;
}
int main(){
    int target;
    cin>>target;
    cout<<judge(target)<<endl;
    return 0;
}