#include<iostream>

//地址：https://www.acwing.com/problem/content/788/

using namespace std;

const int N = 100010;
int p[N];

int n,k;
int quick_sort(int l,int r,int k){
    if(l>=r) return p[k];
    int x=p[l],i=l-1,j=r+1;
    
    while(1){
        while(p[++i]<x);
        while(p[--j]>x);
        if(i>=j) break;
        swap(p[i],p[j]);
    }
    if(k<=j) return quick_sort(l,j,k);
    else return quick_sort(j+1,r,k);
}



int main(){
    
    cin>>n>>k;
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    cout<<quick_sort(0,n-1,k-1);
    return 0;
    
}