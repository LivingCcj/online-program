/*
 * @Description: 二维区间合并：https://www.acwing.com/problem/content/description/761/
 * 
 *美图笔试题目：主要考察二维区间合并问题。
 结构体的小于操作符重载。
 * @Author: ccj
 * @Date: 2020-12-12 21:59:39
 * @LastEditTime: 2020-12-12 22:05:41
 * @LastEditors:  
 */


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;

struct Seg{
    int k;
    int l,r;
    bool operator < (const Seg& s) const{
        if(s.k != k) return k<s.k;
        else if (s.l!=l) return l<s.l;
        else return r<s.r;
    }
};

int merge(vector<Seg> &p){
    vector<Seg> tmp;
    LL res=0;
    sort(p.begin(),p.end());
    
    int ls=-2e9,re=-2e9,k=-2e9;
    
    for(auto item:p){
        if(item.k==k){
            if(re<item.l){
                if(ls!=-2e9) tmp.push_back({k,ls,re}),res+=re-ls+1;
                ls=item.l;
                re=item.r;
            }else{
                re=max(re,item.r);
            }
        }else{
            if(ls!=-2e9) {
                tmp.push_back({k,ls,re});
                res+=re-ls+1;
            }
            k=item.k,ls=item.l,re=item.r;
        }
    }
    if(ls!=-2e9) tmp.push_back({k,ls,re}),res+=re-ls+1;
    p=tmp;
    return res;
}

int main(){
    int n;
    vector<Seg> cols;
    vector<Seg> rows;
    cin>>n;
    int x1,x2,y1,y2;
    while(n--){
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2) cols.push_back({x1,min(y1,y2),max(y1,y2)});
        else rows.push_back({y1,min(x1,x2),max(x1,x2)});
        
    }
    
    LL res=merge(rows)+merge(cols);
    
    for(auto col:cols){
        for(auto row:rows){
            if(row.k>=col.l && row.k<=col.r && row.r>=col.k && row.l <=col.k) res--;
        }
    }
    
    cout<<res<<endl;
    
    return 0;
    
}