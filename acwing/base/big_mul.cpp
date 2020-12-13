/*
 * @Description: 大数乘以小数 https://www.acwing.com/problem/content/795/
 * @Author: ccj
 * @Date: 2020-12-13 10:50:27
 * @LastEditTime: 2020-12-13 10:51:12
 * @LastEditors:  
 */


#include<iostream>
#include<vector>

using namespace std;
//主要考虑进位问题。
vector<int> mul(vector<int> &A,int b){
    vector<int> C;
    int t=0;
    
    for(int i=0;i<A.size() || t; i++){
        if(i<A.size()) t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    return C;
}


int main(){
    string a;
    int b;
    cin>>a>>b;
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    if(b==0){
        cout<<0;
        return 0;
    }
    auto res = mul(A,b);
    
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i];
    }
    return 0;
}