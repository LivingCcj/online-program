/*
 * @Description: 二进制操作
 * @Author: ccj
 * @Date: 2020-12-13 10:22:56
 * @LastEditTime: 2020-12-13 10:28:54
 * @LastEditors:  
 */

#include<iostream>


using namespace std;

int main (){

    int n=10;
    unsigned int x=-n;
    //i=0 表示右数第1位，直到31位
    for(int i=31;i>=0;i--){
        cout<<(n>>i & 1);
    }
    cout<<endl;

    for(int i=31;i>=0;i--){
        cout<<(x>>i & 1);
    }
    return 0;
}