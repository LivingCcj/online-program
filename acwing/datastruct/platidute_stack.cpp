/*
 * @Description: 单调栈的应用：https://www.acwing.com/problem/content/832/
 * 单调递增序列
 * @Author: ccj
 * @Date: 2020-12-13 11:23:06
 * @LastEditTime: 2020-12-13 11:35:44
 * @LastEditors:  
 */


#include<iostream>
#include<stack>
using namespace std;

const int N =100010;

int a[N];

void deal(int n){
    stack<int> tmp;
    for(int i=0;i<n;i++){
        if(tmp.empty()){
            tmp.push(a[i]);
            cout<<"-1 ";
        }else{
            while(!tmp.empty()){
                if(tmp.top()>=a[i]){
                    tmp.pop();
                }else{
                    cout<<tmp.top()<<" ";
                    tmp.push(a[i]);
                    break;
                }
            }
            if(tmp.empty()){
                tmp.push(a[i]);
                cout<<"-1 ";
            }
        }
    }
}


//优化的单调栈 
void deal1(int n){
    stack<int> tmp;
    for(int i=0;i<n;i++){
        while(!tmp.empty() && tmp.top()>=a[i]) tmp.pop();
        if(tmp.empty()) cout<<"-1 ";
        else cout<<tmp.top()<<" ";
        tmp.push(a[i]);
    }

    
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    deal1(n);
    return 0;
}

