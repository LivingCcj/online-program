#include<iostream>

using namespace std;

//题目地址：https://www.acwing.com/problem/content/790/
//逆序数
const int N = 100010;
typedef long long LL;
int p[N],tmp[N];
LL  res=0;
void merge_sort(int l,int r){
    if (l>=r) return;
    int mid = l+r>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int k=0,i=l,j=mid+1;
    while (i<=mid && j<=r)
    {
        if(p[i]<=p[j]) tmp[k++]=p[i++];
        else{
            res+=mid-i+1;
            tmp[k++]=p[j++];
        }
    }
    while(i<=mid) tmp[k++]=p[i++];
    while(j<=r) tmp[k++] = p[j++];

    for(int s=0;s<k;s++) p[s+l]=tmp[s];
    
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    merge_sort(0,n-1);
    cout<<res;
    return 0;
}