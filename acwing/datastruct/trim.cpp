/*
 * @Description: 字典树的操作 ：https://www.acwing.com/problem/content/837/
 * 
 * 主要是字典树的插入和更新操作
 * 核心：记录上一个父节点的位置。
 * @Author: ccj
 * @Date: 2020-12-13 22:17:56
 * @LastEditTime: 2020-12-13 22:32:37
 * @LastEditors:  
 */


#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int N =1e5+10;


int son[N][26],mark[N],idx; //idx表示上一个父节点的位置。


void insert(char str[]){
    int p=0; //所有的父节点都是0
    for(int i=0;str[i];i++){
        int x=str[i]-'a';
        if(!son[p][x]) son[p][x]=++idx;
        p=son[p][x];
    }
    mark[p]++;
}

int query(char str[]){
    int p=0; //查询从父节点0开始
    for(int i=0;str[i];i++){
        int x=str[i]-'a';
        if(son[p][x]) p=son[p][x];
        else return 0;
    }
    return mark[p];
}

int main(){
    int n;
    cin>>n;
    
    char str[N];
    while(n--){
        char op[2];
        
        scanf("%s %s",op,str);

        if(op[0]=='I') insert(str);
        else cout<<query(str)<<endl;
    }
    return 0;
}
