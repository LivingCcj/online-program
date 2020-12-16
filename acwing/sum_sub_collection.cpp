/*
 * @Description: 子集合的和为某个值：https://blog.csdn.net/qq_26584263/article/details/106381117
 * @Author: ccj
 * @Date: 2020-12-15 22:40:31
 * @LastEditTime: 2020-12-15 23:02:57
 * @LastEditors:  
 */


#include<iostream>
#include<algorithm>
using namespace std;

const int N= 1e5+10;

int a[N];
int target;
int res=0;
int n;

void getSum(int st,int sum){
    while(st<=n){
        int num=a[st];
        if(num>sum){
            return ;
        }
        cout<<sum<<"  ";
        if(sum==num){
            res++;
            return;
        }
        getSum(++st,sum-num);
    }
}
int main(){
    cin>>n>>target;
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n,greater<int>());
    for(int i=1;i<=n;i++) cout<<a[i];
    getSum(1,target);
    cout<<endl;;
    cout<<res;
    return 0;
}   
