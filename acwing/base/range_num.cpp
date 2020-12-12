#include<iostream>



//题目地址:https://www.acwing.com/problem/content/791/

//数的存在的范围，有序数据
using namespace std;
const int N =100010;

int n,q,p[N];

void range_num(int q){
    int i=0,j=n-1;
    while(i<j){
        int mid=i+j>>1;
        if(p[mid]>=q) j=mid;
        else i=mid+1;
    }
    if (p[i]!=q){
        cout<<"-1 -1"<<endl;
        return;
    }
    int l=0;
    int r=n-1;
    while (l<r)
    {
        int mid=l+r+1>>1;
        if(p[mid]<=q) l=mid;
        else r=mid-1;
    }
    cout<<i<<" "<<r<<endl;
    return;
}

int main(){

    cin>>n>>q;

    for(int i=0;i<n;i++) cin>>p[i];
    while (q--)
    {
        int k;
        cin>>k;
        range_num(k);
    }
    
}