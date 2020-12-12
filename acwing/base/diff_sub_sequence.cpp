/*
 * @Description: 最长不同连续自序列；https://www.acwing.com/problem/content/801/
 * 
 * 属于双指针算法 
 * 核心是 找单调性
 * for(int i,j=0){
 *    while(i<j && check(j)) j++
 *     // do your work.
 * }
 * @Author: ccj
 * @Date: 2020-12-12 16:21:45
 * @LastEditTime: 2020-12-12 16:55:30
 * @LastEditors:  
 */

#include<iostream>

using namespace std;

const int N = 100010;
int a[N],s[N];

int main(){
    int n;
    cin>>n;
    int j=0;
    int r=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ++s[a[i]];   // 可以用set进行空间优化
        while(s[a[i]]>1){
            --s[a[j++]];   //如果有重复的向右移动。
        }
        r=max(r,i-j+1);
    }
    cout<<r;
    return 0;
}
