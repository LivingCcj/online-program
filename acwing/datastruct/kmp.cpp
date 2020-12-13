/*
 * @Description: 模式匹配：https://www.acwing.com/problem/content/833/
输出字串p（小字符串）在字串s（大字符串）中的起始位置。
//时间复杂O<M>
 * @Author: ccj
 * @Date: 2020-12-13 21:36:51
 * @LastEditTime: 2020-12-13 21:51:32
 * @LastEditors:  
 */


#include<iostream>

using namespace std;

const int N=1e5+10,M=1e6+10;

int n,m;

char p[N],s[M];

int ne[N];


int main(){
    cin>>n>>p+1>>m>>s+1;
    

    //构造next函数：最前缀==最后缀字符串
    for(int i=2,j=0;i<=n;i++){
        
        while(j && p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }
    
    //kmp匹配两个字符串
    for(int i=1,j=0;i<=m;i++){ 
        while(j && s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==n){ 
            cout<<i-n<<" ";
            j=ne[j];
        }
    }
    return 0;
}